#ifndef led_pattern_included
#define led_pattern_included

#define default_pattern    0
#define gs1_pattern        1
#define gs2_pattern        2
#define gs3_pattern        3
#define gs4_pattern        4

void led_pattern_update();
void led_default();
void led_pattern1();
void led_pattern2();
void led_pattern3();
void led_pattern4();

extern int led_pattern_state;

#endif
