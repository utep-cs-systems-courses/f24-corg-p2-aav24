//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT &= ~LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

short green_on = 0;
short red_on = 1;

void toggle_green(){

  if(green_on){
    green_on = 0;
    P1OUT &= ~LED_GREEN;
  } else {
    green_on = 1;
    P1OUT |= LED_GREEN;
  }
}

void toggle_red(){

  if(red_on){
    red_on = 0;
    P1OUT &= ~LED_RED;
  } else {
    red_on = 1;
    P1OUT |= LED_RED;
  }
}

int counter = 0;
int on_limit = 25;

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // modify so that light appears dim
  // make it to where the LED flashes on and off quickly

  // green led is on
  if(counter < on_limit){
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }

  counter++;

  if(counter >= 100){
     counter = 0;
  }
  
  // how would I dim gradually?
} 

