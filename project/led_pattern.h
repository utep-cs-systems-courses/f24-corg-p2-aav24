#ifndef led_pattern_included
#define led_pattern_included

#define default_pattern    0
#define gs1_pattern        1
#define gs2_pattern        2
#define gs3_pattern        3
#define gs4_pattern        4

void led_pattern_update();
void led_default();
void led_blink();
void led_dim();
void led_rapid_blink();
void led_transition();

extern int led_pattern_state;

#endif
