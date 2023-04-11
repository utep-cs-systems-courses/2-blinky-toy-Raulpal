#include <msp430.h>
#include "buzzer.h"
#include "musicNotes.h"

int happy_BDAY[23] = {5102, 5102, 4545, 5102, 3822, 4050, 5102,5102,4545, 5102,3405,3822, 5102,5102,2551, 4050, 4545, 2863, 2863, 3034,3822,3405,3405};

int mario_theme[] = {

  659, 659, 0, 659, 0, 523, 659, 0, 784, 0, 392, 0, 523, 0,

  392, 0, 330, 0, 440, 0, 494, 0, 466, 0, 440, 0, 392, 0, 659, 0,

  784, 0, 880, 0, 698, 0, 784, 0, 659, 0, 523, 0, 587, 0, 494, 0,

  523, 0, 392, 0, 330, 0, 440, 0, 494, 0, 466, 0, 440, 0, 392, 0

}; // 62
int mario_theme_durations[] = {

  1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1,

  2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

  1, 1, 1, 1, 1, 1

};// 62

int sound[7] = {302,302,255,255,277,277,255};
void delay_duration( int duration)
{
  int cycles = (1000 * duration);

   while (cycles--)
    __delay_cycles(2000);
  //delay_cycles(1000 * ms);
}
void play_note(int note, int duration)
{
  buzzer_set_period(note);
  delay_duration(duration);

}

