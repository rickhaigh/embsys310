#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define BIT5 (1<<5)
#define dot 1
#define dash 3
#define inletter_sp 1   // space between dots and dashes in the same letter
#define btwnletter_sp 3 // space between two letters        
#define btwnword_sp 7   // space between two words
#define letter_r 

void delay_a(int ms);

int main()
{
    volatile int counter;
    int clocks = CLOCKS_PER_SEC;
    clock_t begin, end;
    double time_spent;
    
    
    RCC_AHB2ENR |= 0x1; // RCC_AHB2ENR: Enable clock to GPIOA

    GPIOA_MODER = 0xABFFF7FF; // GPIOA_MODER: Set GPIOA 5 to output
    
    while(1) {    
        
        GPIOA_ODR ^= BIT5; // GPIOA_ODR: toggle LED1 (PA5) on (toggle bit 5)
        
        counter = 0;
//        begin = clock();
//        delay_ms(1000);
        while (counter < 1) {
            counter++;
        }    
//        end = clock();
//        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    }
}

void delay_a(int ms) {
    int counter = 0;
    while (counter <= ms) {
        counter++;
    }    
}