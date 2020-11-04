#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define BIT5 (1<<5)

#define SCALE 10  // factor used to scale timing for system

static const uint8_t letters[] = 
{
    //  Read from left to right, 1 = dot, 2 = dash, 3 = space between parts of same letter
    //  4 = space between letters, 5 = space between words, 6 = blank/unused space    
    1, 2, 6, 6, 6, // A
    2, 1, 1, 1, 6, // B
    2, 1, 2, 1, 6, // C
    2, 1, 1, 6, 6, // D
    1, 6, 6, 6, 6, // E
    1, 1, 2, 1, 6, // F
    2, 2, 1, 6, 6, // G
    1, 1, 1, 1, 6, // H
    1, 1, 6, 6, 6, // I
    1, 2, 2, 2, 6, // J
    2, 1, 2, 6, 6, // K
    1, 2, 1, 1, 6, // L
    2, 2, 6, 6, 6, // M
    2, 1, 6, 6, 6, // N
    2, 2, 2, 6, 6, // O
    1, 2, 2, 1, 6, // P
    2, 2, 1, 2, 6, // Q
    1, 2, 1, 6, 6, // R
    1, 1, 1, 6, 6, // S
    2, 6, 6, 6, 6, // T
    1, 1, 2, 6, 6, // U
    1, 1, 1, 2, 6, // V
    1, 2, 2, 6, 6, // W
    2, 1, 1, 2, 6, // X
    2, 1, 2, 2, 6, // Y
    2, 2, 1, 1, 6  // Z
};

const uint8_t* getcode(char c) {
    return &letters[5*(c - 'a')];
}

void sendchar(const uint8_t* x) {
    uint8_t i;
    int j;
    // Timing measurements:
    // count1=10000*5= 63ms (dot)
    // count3=30000*5= 188ms (dash)
    // count1=10000*10= 128ms (dot)
    // count3=30000*10= 378ms (dash)

    int count1 = 10000*SCALE;
    int count2 = 20000*SCALE*0.5;  // scale inter letter space, because count2*SCALE + system overhead does not match count3
    int count3 = 30000*SCALE;
    // turn off led for one time unit (space between parts of same letter)
    
    for(i=0; i < 5; i++) {        
        
        GPIOA_ODR &= ~BIT5; // GPIOA_ODR: turn off LED1 (PA5) on (set bit 5)
        for(j=0;j < count1; j++){} // delay for count1 counts
        
        if (*(x+i) == 1) {
            // turn on led for one time unit
            //printf("dot ");
            GPIOA_ODR |= BIT5; // GPIOA_ODR: turn on LED1 (PA5) on (set bit 5)
            for(j=0;j < count1; j++){} // delay for count1 counts
                               
        } else if (*(x+i) == 2) {
            // turn on led for three time units
            //printf("dash ");
            GPIOA_ODR |= BIT5; // GPIOA_ODR: turn on LED1 (PA5) on (set bit 5)
            for(j=0;j < count3; j++){} // delay for count3 counts
        } else if (*(x+i) == 6) {
            // turn off led for three time units (space between letters)
            //printf("  ");
            GPIOA_ODR &= ~BIT5; // GPIOA_ODR: turn off LED1 (PA5) on (set bit 5)
            for(j=0;j < count2; j++){} // delay for additional count2 counts, total count3 between end of letter and start of the next
            break;
        }
    }
    
}

int main()
{    
    //char name[] = "eost"; 
    char name[] = "rick";
    uint8_t name_len = strlen(name);
    uint8_t j;
    
    RCC_AHB2ENR |= 0x1; // RCC_AHB2ENR: Enable clock to GPIOA

    GPIOA_MODER = 0xABFFF7FF; // GPIOA_MODER: Set GPIOA 5 to output
    
    for(j=0;j<name_len; j++) {
        char c = name[j];
        const uint8_t* xcode;
        xcode = getcode(c);
        //printf("%c :", c);
        sendchar(xcode);
        //printf(":\n");
    }
    return 0;
}