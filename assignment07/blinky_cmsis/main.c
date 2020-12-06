#include "stm32l475xx.h"
#include "stm32l4xx_it.h"
#include "delay.h"

#define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969    
volatile uint32_t g_ms_tick;

void SysTick_Initialize(void);

void main()
{
    // Enable RCC GPIOB Periph clock
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; 
    
    // Set bit[29:28] to 0x01
    GPIOB->MODER &= ~GPIO_MODER_MODE14_1; // Clear [29] bit
    GPIOB->MODER |= GPIO_MODER_MODE14_0;  // Set [28] bit
 
    SysTick_Initialize();
    while(1) 
    {
        GPIOB->ODR ^= GPIO_ODR_OD14; // Toggle bit 14
        delay_ms(300);
    }
}

// Function to initialize and enable SysTick
void SysTick_Initialize(void) 
{
    SysTick->LOAD = (SYS_CLOCK_HZ-1)/1000;  // 1ms count down
    SysTick->VAL = 0x0;
    SysTick->CTRL = 0x7;
    
}

void SysTick_Handler(void) 
{
    __disable_irq();
    g_ms_tick++;
    __enable_irq();
}