#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"

char switch_state_changed;

void switch_init(){
  P2REN |= SW1;     //enables resistor for S1
  P2IE  |= SW1;     //enables interrupts for S1
  P2IES |= SW1;     //sets S1 edge sense interrupt to the falling edge (button is pressed down)
  P2OUT |= SW1;     //sets P2.0 OUT to 1 so the button can be read
  P2DIR &= ~SW1;    //set S1 as input
  
}

void switch_interrupt_handler(){
  //Use this to determine which switch or switches are pressed... when you read multiple buttons
  char p2val = P2IN;
  state_advance();
}
