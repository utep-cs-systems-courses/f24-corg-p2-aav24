#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "led_pattern.h"

char switch_state_down, switch_state_changed;

static char
switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);    /* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);    /* if switch down, sense up */
  return p2val;
}

void
init_switches(){
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  if(!(p2val & GS1)){    /* switch 1 is pressed */
    led_pattern_state = gs1_pattern;
  } else if (!(p2val & GS2)){
    led_pattern_state = gs2_pattern;
  } else if (!(p2val & GS3)){
    led_pattern_state = gs3_pattern;
  } else if (!(p2val & GS4)){
    led_pattern_state = gs4_pattern;
  }
  switch_state_changed = 1;
  led_update();
}
