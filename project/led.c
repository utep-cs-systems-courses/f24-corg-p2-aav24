#include "led.h"
#include <msp430.h>
#include "led_pattern.h"
// implements functions for led.h

char green_state = 0;
char red_state = 0;

// initializes leds for output
void led_init(){
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;
}

// turns on red led
void red_on(){
  P1OUT |= LED_RED;
  red_state = 1;
}

// turns on green led
void green_on(){
  P1OUT |= LED_GREEN;
  green_state = 1;
}

// turns both leds on
void leds_on(){
  red_on();
  green_on();
}

// turns red led off
void red_off(){
  P1OUT &= ~LED_RED;
  red_state = 0;
}

// turns green led off
void green_off(){
  P1OUT &= ~LED_GREEN;
  green_state = 0;
}

// turns both leds off
void leds_off(){
  red_off();
  green_off();
}

// toggles red led
void toggle_red(){
  if(red_state){
    red_off();
  } else {
    red_on();
  }
}

// toggles green led
void toggle_green(){
  if(green_state){
    green_off();
  } else {
    green_on();
  }
}

// toggles both leds
void toggle_leds(){
  toggle_red();
  toggle_green();
}

void led_update(){
  led_pattern_update();
}
