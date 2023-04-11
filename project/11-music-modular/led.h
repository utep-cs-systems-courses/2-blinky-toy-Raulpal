#ifndef Led_included
#define Led_included

#define RED_LED BIT6
#define GREEN_LED BIT0
#define LEDS (RED_LED | GREEN_LED)

void led_init();
void redControl();
void greenControl();

#endif // included
