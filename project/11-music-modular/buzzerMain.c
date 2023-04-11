#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "led.h"


int main() {
    configureClocks();

    led_init();
   
    switch_init();
    buzzer_init();
    
    or_sr(0x18);          // CPU off, GIE on
}

