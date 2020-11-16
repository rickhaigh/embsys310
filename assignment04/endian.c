// Test to demonstrate endianess 
#include <stdint.h>


int main() {
    int number = 0x12345678;
    //int *p_number = &number;
    uint8_t *p_small = (uint8_t*)&number;
    int a,b,c,d;
        
    a = *(p_small+0); // base address of int number
    b = *(p_small+1);
    c = *(p_small+2);
    d = *(p_small+3);
    
    
    return 0;
}