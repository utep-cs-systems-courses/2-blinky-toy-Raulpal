//#include <msp430.h>
#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)

void switch_init();
void switch_interrupt_handler();
void __interrupt_vec(PORT2_VECTOR) Port_2(); 
#endif // included
