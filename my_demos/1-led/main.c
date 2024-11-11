//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

// turns green LED on
void green_ON(){

  P1OUT |= LED_GREEN;

}
// turnes red LED on
void red_ON(){

  P1OUT |= LED_RED;

}
// turns green LED off
void green_OFF(){

  P1OUT &= ~LED_GREEN;
  
}
// turns red LED off
void red_OFF(){

  P1OUT &= ~LED_RED;

}

int main(void) {
  P1DIR |= LEDS;
  green_ON();
  red_ON();

  or_sr(0x18);		/* CPU off, GIE on */
}
