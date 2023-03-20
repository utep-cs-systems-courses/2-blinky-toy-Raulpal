#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only 1 switch on this board */

// defining up and down states
#define up_on 0
#define dn_on 1
#define up_off 2
#define dn_off 3

char button_state = up_on;


void main(void) 
{  
  configureClocks();

  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */

  or_sr(0x18);  // CPU off, GIE on
}
up_event()
{
  P1OUT |= LED_RED;
  P1OUT &= ~LED_GREEN;
}

dn_event()
{
   P1OUT |= LED_GREEN;
   P1OUT &= ~LED_RED;
}

void
switch_interrupt_handler()
{
  char p1val = P1IN;		/* switch is in P1 */

/* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  
  if (button_state == up_on) {
    up_event();
    button_state = dn_off;
  }
  else if (button_state == dn_off) {
    dn_event();
    button_state = up_off;
  }
  else if (button_state == up_off) {
    dn_event();
    button_state = dn_on;
  }
  else if (button_state == dn_on) {
    up_event();
    button_state = up_on;

  }
  
}


/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}
