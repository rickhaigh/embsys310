#include "stm32l4xx_it.h"

#pragma section="CSTACK"    // this provides us access to CSTACK limit

void __iar_program_start(void); // Need to provide a definition so we can use it.  Real definition will be found later

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void Default_Handler(void);

// Vector table entries can be found in Cortex-M4 devices generic user guide pg 2-24 (37)
const int __vector_table[] @ ".intvec" = {  // const required to have intvec use rom storage, .intvec is where we want our table stored
    (int) __section_end("CSTACK"),  // Top of Stack, SP starting point: automatically finds proper place for SP to point to even if we change stack size
    (int) __iar_program_start,      // Pointer to reset handler, (int) typecast needed, here is where we want to get the correct starting PC address
    (int) NMI_Handler,
    (int) HardFault_Handler,
    (int) MemManage_Handler,
    (int) BusFault_Handler,
    (int) UsageFault_Handler,
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    (int) SVC_Handler,
    (int) DebugMon_Handler,
    0,      // Reserved
    (int) PendSV_Handler,
    (int) SysTick_Handler
};


void NMI_Handler(void)
{
    while(1)
    {
    }
}

// When the SP register drops below the start of RAM,
// the processor enters the HardFault exception
void HardFault_Handler(void)
{
    Default_Handler();
}

void MemManage_Handler(void)
{
    while(1)
    {
    }
}

void BusFault_Handler(void)
{
    while(1)
    {
    }
}

void UsageFault_Handler(void)
{
    while(1)
    {
    }
}

void Default_Handler(void)
{
    while(1)
    {
    }
}

#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler