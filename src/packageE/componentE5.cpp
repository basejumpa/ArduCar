#include "componentE5.h"

static int state = led_state_off;

void componentE5_init(void){
}


void componentE5_loop(void){
   /** Toggle while white button is pressed. Always start with on. */
   if(digitalRead(pin_white_button) == button_state_pressed){
	  state = !state;
   }else{
	  state = led_state_off;
   }

   /** Actuation (only for on) */
   if(state == led_state_on){
	  digitalWrite(pin_white_led, led_state_on);
   }else{
	  /** No actuation for off. */
   }
}


void componentE5_setU(int){
}


int componentE5_getY(void){
	return 0;
}
