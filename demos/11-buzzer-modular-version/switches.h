#ifndef switches_included
#define switches_included

#define SW1 BIT1
#define SWITCHES SW1

#define s1_on 0
#define s2_on 1
#define s3_on 2
#define s4_on 3

//extern char button_state = s1_on;

void switch_init();
void switch_interrupt_handler();

#endif // included
