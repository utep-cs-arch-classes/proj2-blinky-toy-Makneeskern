#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"

char switch_state_changed;

void switch_init(){
  P2REN |= SWITCHES;     //enables resistor for S1
  P2IE  |= SWITCHES;     //enables interrupts for S1
  P2IES |= SWITCHES;     //sets S1 edge sense interrupt to the falling edge (button is pressed down)
  P2OUT |= SWITCHES;     //sets P2.0 OUT to 1 so the button can be read
  P2DIR &= ~SWITCHES;    //set S1 as input
  
}

void switch_interrupt_handler(){
  //Use this to determine which switch or switches are pressed... when you read multiple buttons
  char p2val = P2IN;

  //activates when both SW1 and SW3 are pressed down
  if(p2val == 0b00001110){
    substate = 0;
    switch(state){
    case 0:
    case 2:
      state = 1;
      break;
    case 1:
      state = 0;
      break;
    }
  }
  else if(p2val == 0b00001101){
    substate = 0;
    switch(state){
    case 0:
      state = 2;
      break;
    case 2:
      state = 0;
      break;
    }
  }
  substate_advance();
}
