#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

static char blink_count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  if (++blink_count == 125 && state == 0) {
    substate_advance();
    blink_count = 0;
  }
  else if(blink_count == 3 && state == 1){
    substate_advance();
    blink_count = 0;
  }
}

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SW1){
    P2IFG &= ~SW1;
    switch_interrupt_handler();
    blink_count = 0;
  }
}
