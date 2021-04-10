#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

unsigned char state = 0;
unsigned char substate = 0;

void state_advance(){
  substate = 0;
  switch(state){
  case 0:
    state = 1;
    break;
  case 1:
    state = 0;
    break;
  }
  substate_advance();
}

void substate_advance(){
  char changed = 0;
  switch(state){
  case 0:
    switch(substate){
    case 0:
      red_on = 1;
      green_on = 0;
      changed = 1;
      substate = 1;
      break;
    case 1:
      red_on = 0;
      green_on = 1;
      changed = 1;
      substate = 0;
      break;
    }
    break;
  case 1:
    switch(substate){
    case 0:
      red_on = 1;
      green_on = 0;
      changed = 1;
      substate = 1;
      break;
    case 1:
      red_on = 0;
      green_on = 0;
      changed = 1;
      substate = 0;
      break;
    }
    break;
  }

  led_changed = changed;
  led_update();
}
