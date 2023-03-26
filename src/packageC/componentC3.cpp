#include "componentC3.h"

static int state = led_state_off;

void componentC3_init(void){
}


void componentC3_loop(void){
   /** Toggle while blue button is pressed. Always start with on. */
   if(digitalRead(pin_blue_button) == button_state_pressed){
	  state = !state;
   }else{
	  state = led_state_off;
   }

   /** Actuation (only for on) */
   if(state == led_state_on){
	  digitalWrite(pin_blue_led, led_state_on);
   }else{
	  /** No actuation for off. */
   }
}


void componentC3_setU(int){
}


int componentC3_getY(void){
	return 0;
}
