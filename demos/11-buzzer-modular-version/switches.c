#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

void switch_init()
{
  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

}

void switch_interrupt_handler()
{

  char p2val = P2IN;

  /* update switch interrupt to detect changes from current buttons */

  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */

  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */


  if (p2val & SW1) {
    buzzer_set_period(0);
    //button_state == s2_on;
  }else{
    buzzer_set_period(1000);
  }
 
}

void __interrupt_vec(PORT2_VECTOR) Port_2()
{

  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */

    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }

}
