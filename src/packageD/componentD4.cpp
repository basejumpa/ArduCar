#include "componentD4.h"

static int state = led_state_off;

void componentD4_init(void){
}


void componentD4_loop(void){
   /** Toggle while green button is pressed. Always start with on. */
   if(digitalRead(pin_green_button) == button_state_pressed){
	  state = !state;
   }else{
	  state = led_state_off;
   }

   /** Actuation (only for on) */
   if(state == led_state_on){
	  digitalWrite(pin_green_led, led_state_on);
   }else{
	  /** No actuation for off. */
   }
}


void componentD4_setU(int){
}


int componentD4_getY(void){
	return 0;
}
