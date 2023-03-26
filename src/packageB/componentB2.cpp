#include "componentB2.h"

static int state = led_state_off;

void componentB2_init(void){
}


void componentB2_loop(void){
   /** Toggle while yellow button is pressed. Always start with on. */
   if(digitalRead(pin_yellow_button) == button_state_pressed){
	  state = !state;
   }else{
	  state = led_state_off;
   }

   /** Actuation (only for on) */
   if(state == led_state_on){
	  digitalWrite(pin_yellow_led, led_state_on);
   }else{
	  /** No actuation for off. */
   }
}


void componentB2_setU(int){
}

int componentB2_getY(void){
	return 0;
}
