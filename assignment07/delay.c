#include "delay.h"

// Delay ms - delays for num_ms number of milliseconds
void delay_ms (uint32_t num_ms) {
    
    g_ms_tick = 0;  // reset count to start new delay
    while (g_ms_tick < num_ms);

}
