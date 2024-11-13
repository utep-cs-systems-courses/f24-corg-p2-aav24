#include "led.h"
#include <msp430.h>
#include "led_pattern.h"
// implements functions for led.h

// initializes leds for output
void led_init(){
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;
}
// turns on red led
void red_on(){
  P1OUT |= LED_RED;
}
// turns on green led
void green_on(){
  P1OUT |= LED_GREEN;
}
// turns both leds on
void leds_on(){
  red_on();
  green_on();
}
// turns red led off
void red_off(){
  P1OUT &= ~LED_RED;
}
// turns green led off
void green_off(){
  P1OUT &= ~LED_GREEN;
}
// turns both leds off
void leds_off(){
  red_off();
  green_off();
}
// toggles red led
void toggle_red(){
  P1OUT ^= LED_RED;
}
// toggles green led
void toggle_green(){
  P1OUT ^= LED_GREEN;
}
// toggles both leds
void toggle_leds(){
  toggle_red();
  toggle_green();
}
void led_update(){
  led_pattern_update();
}
