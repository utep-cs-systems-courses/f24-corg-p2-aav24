#ifndef led_included
#define led_included

#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)


void led_init();
void red_on();
void green_on();
void leds_on();
void red_off();
void green_off();
void leds_off();
void toggle_red();
void toggle_green();
void toggle_leds();
void led_update();

#endif
