#include <msp430.h>
#include "timerLib/libTimer.h"
#include "buzzer.h"
#include "led.h"

extern int counter;

void buzzer_init(){

  timerAUpmode();    /* used to drive speaker */
  P2SEL &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;    /* enable output to speaker */
  
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;    /* one half cycle */
}

void buzzer_off(){
  buzzer_set_period(0);
}

void blink_buzzer(){
  if(red_state){
    buzzer_set_period(4000);
  }else{
    buzzer_set_period(1000);
  }
}


short high_freq = 4000;
short low_freq = 2000;
short low = 0;
void siren_buzzer(){
  if (counter % 10 == 0){
    if(low){
      buzzer_set_period(2000);
      low = 0;
    } else {
      buzzer_set_period(4000);
      low = 1;
    }
  }
}
