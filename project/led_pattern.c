#include <msp430.h>
#include "led_pattern.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

extern int led_pattern_state;

extern unsigned int counter;

extern char switch_state_down;


void led_default(){
  leds_off();
}

void led_blink(){
  if (counter < 125){
    green_on();
    if (counter % 25 == 0){
      toggle_red();
      blink_buzzer();
    }
  } else {
    red_on();
    if (counter %25 == 0){
      toggle_green();
    }
  }

  
}

short min = 0;
short max = 1000;
short current = 0;

void led_dim(){
  buzzer_set_period(0);
  if (counter % 2 == 0){
    toggle_red();
    toggle_green();
  }
}

void led_rapid_blink(){
  siren_buzzer();
  if (counter % 10 == 0){
    toggle_green();
    toggle_red();
  }
}

void led_transition(){
  toggle_green();
  toggle_red();

  if(red_state){
    buzzer_set_period(1000);
  } else {
    buzzer_set_period(0);
  }
}

void led_pattern_update(){
  // performs led patterns based on the switch that was pressed
  switch(led_pattern_state){
  case default_pattern:
    led_default();
    
    break;
  case gs1_pattern:
    led_blink();
    break;
  case gs2_pattern:
    led_dim();
    break;
  case gs3_pattern:
    led_rapid_blink();
    break;
  case gs4_pattern:
    if (switch_state_down){
      led_transition();
      switch_state_down = 0;
    } 
    break;
  default:
    led_default();
    break;
  }
  
}
