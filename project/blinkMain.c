//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "../demos/timerLib/libTimer.h"
#include "led.h"
#include "switches.h"

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  switch_init();
  led_init();
  enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}
