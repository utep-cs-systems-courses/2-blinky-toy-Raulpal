#include <msp430.h>
#include "switches.h"
#include "playNotes.h"

void switch_init()
{

  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

}
//unsigned int sound[7] = {302,302,255,255,227,227,255};
void switch_interrupt_handler()
{
  char p2val = P2IN;

  /* update switch interrupt to detect changes from current buttons */

  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */

  switch_pressed_play_sound(p2val);
  
}

void __interrupt_vec(PORT2_VECTOR) Port_2()
{

  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */

    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }

}
