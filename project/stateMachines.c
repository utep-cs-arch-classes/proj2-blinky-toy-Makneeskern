#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

unsigned char state = 0;

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;
  switch(state){
  case 0:
    red_on = 0;
    green_on = 1;
    changed = 1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    green_on = 1;
    changed = 1;
    state = 2;
    break;
  case 2:
    red_on = 0;
    green_on = 0;
    changed = 1;
    state = 3;
    break;
  case 3:
    red_on = 0;
    green_on = 0;
    changed = 1;
    state = 0;
    break;
  }

  led_changed = changed;
  led_update();
}



