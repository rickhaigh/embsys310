
#define RCC_BASE 0x40021000
#define RCC_BASE_BB 0x42000000
#define RCC_BASE_BB_OFFSET (0x21000 + 0x4C)
#define GPIOA_BASE 0x48000000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define RCC_AHB2ENR_BB (*((unsigned int*)((RCC_BASE_BB)+(RCC_BASE_BB_OFFSET *32)+(0*4))))

#define BIT5 (1<<5)

int main()
{
    volatile int counter;
    
    // RCC_AHB2ENR |= 0x1; // RCC_AHB2ENR: Enable clock to GPIOA using bit banding
    //RCC_AHB2ENR_BB = 0x1;
    *((unsigned int*)((0x42000000)+(0x2104C*32)+(0*4))) = 0x1;
    GPIOA_MODER = 0xABFFF7FF; // GPIOA_MODER: Set GPIOA 5 to output
    
    while(1) {    
        
        GPIOA_ODR ^= BIT5; // GPIOA_ODR: toggle LED1 (PA5) on (toggle bit 5)
        
        counter = 0;
        while (counter < 100000) {
            counter++;
        }    
    }
}