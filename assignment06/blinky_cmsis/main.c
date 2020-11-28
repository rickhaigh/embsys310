#include "stm32l475xx.h"
#include "delay.h"


void main()
{
    // Enable RCC GPIOB Periph clock
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; 
    
    // Set bit[29:28] to 0x01
    GPIOB->MODER &= ~GPIO_MODER_MODE14_1; // Clear [29] bit
    GPIOB->MODER |= GPIO_MODER_MODE14_0;  // Set [28] bit
    
    while(1) {
        GPIOB->ODR |= GPIO_ODR_OD14; // Set bit 14;
        delay(100000);
        
        GPIOB->ODR &= ~GPIO_ODR_OD14; // Clear bit 14;
        delay(100000);
        
    }
    //return 0;
}
