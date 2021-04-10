#ifndef switches_included
#define switches_included

#define SW1 BIT0  //switch1 on extension board, P2.0
#define SW2 BIT1  //switch2 on extension board, P2.1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (BIT0 | BIT1 | BIT2 | BIT3)

void switch_init();
void switch_interrupt_handler();

extern char switch_state_changed;

#endif
