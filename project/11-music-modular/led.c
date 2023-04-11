#include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS; // set which bits we will use
  P1OUT &= ~GREEN_LED;
  P1OUT &= ~RED_LED;
  
}

void greenControl()
{
  P1OUT ^= GREEN_LED;
}

void redControl()
{
  P1OUT ^= RED_LED;
}
