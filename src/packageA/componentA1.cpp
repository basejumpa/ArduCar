#include "componentA1.h"
 
static int state = led_state_on;

void componentA1_init(void){
}


void componentA1_loop(void){
   /** Toggle while red button is pressed. Always start with on. */
   if(digitalRead(pin_red_button) == button_state_pressed){
      state = !state;
   }else{
      state = led_state_off;
   }

   /** Actuation (only for on) */
   if(state == led_state_on){
      digitalWrite(pin_red_led, led_state_on);
   }else{
      /** No actuation for off. */
   }
}


void componentA1_setU(int){
}


int componentA1_getY(void){
	return 0;
}
