#include <stdint.h>
volatile extern uint32_t g_ms_tick;   // global ms count used by delay()

void delay_ms (uint32_t num_ms);