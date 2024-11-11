#ifndef switches_included
#define switches_included

#define GS1 BIT0
#define GS2 BIT1
#define GS3 BIT2
#define GS4 BIT3

#define SWITCHES (GS1 | GS2 | GS3 | GS4)

void init_switches();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed;

#endif
