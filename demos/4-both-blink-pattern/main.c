//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  // P1OUT &= ~LED_RED;
  //P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state vars that control green blinking 
int greenBlinkLimit = 7;  // duty cycle = 1/blinkLimit, larger value at bottom for dimer light first
int greenBlinkCount = 0;  // cycles 0...blinkLimit-1
int greenSecondCount = 0; // state var representing repeating time 0…1s

// gloabl state var that controla red blinking
int redBlinkLimit = 3; // duty cycle
int redBlinkCount = 0; // cycles
int redSecondCount = 0; // state var representing time

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle green blinking 
  greenBlinkCount ++;
 
  if (greenBlinkCount >= greenBlinkLimit) { // on for 1 interrupt period
    greenBlinkCount = 0;
    P1OUT |= LED_GREEN;
  } else		          // off for blinkLimit - 1 interrupt periods
    P1OUT &= ~LED_GREEN;

  // handle red blinking
  redBlinkCount ++;
  if (redBlinkCount >= redBlinkLimit) {
    redBlinkCount = 0;
    P1OUT |= LED_RED;
  }else
    P1OUT &= ~LED_RED;

  
  // measure a second for green led
  greenSecondCount ++;
  if (greenSecondCount >= 250) {  // once each second
    greenSecondCount = 0;
    greenBlinkLimit --;	 // increase duty cycle   
    if (greenBlinkLimit <= 0)    
      greenBlinkLimit = 7;    // reset blinklimit back to intial value
  }

  // measure a second for red led
  redSecondCount ++;
  if (redSecondCount >= 63) {
    redSecondCount = 0;
    redBlinkLimit ++;
    if (redBlinkLimit >= 8)
      redBlinkLimit = 0;
  }
} 

