#include "delay.h"

// Delay ms - delays for num_ms number of milliseconds
// NOTE: Remember that SysTick timer does not run during debugging when the processor is halted

void delay_ms (uint32_t num_ms) {
    
    g_ms_tick = 0;             // reset count to start new delay
    // SysTick->CTRL = 0x7;    // Enable systick timer
    while (g_ms_tick < num_ms);// Wait for num_ms to run out
    // SysTick->CTRL = 0x0;    // disable systick timer
}
