#include <msp430.h>
#include "led.h"
#include "timerLib/libTimer.h"
#include "switches.h"
#include "led_pattern.h"

volatile int counter = 0;
int led_pattern_state = default_pattern;


void main(void){

  configureClocks();
  init_switches();
  led_init();

  or_sr(0x18); // turn CPU off

}

void
__interrupt_vec(PORT2_VECTOR) Port_2()
{
  if (P2IFG & SWITCHES){    /* checks if a switch caused this interrupt */
    P2IFG &= ~SWITCHES;    /* clears pending interrupt flags */
    switch_interrupt_handler();
  }
}