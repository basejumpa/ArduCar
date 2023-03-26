#include "packageB.h"
#include "componentB1.h"
#include "componentB2.h"
#include "componentB3.h"
#include "componentB4.h"
#include "componentB5.h"
#include "componentB6.h"


void packageB_init(void){
   /** Setup GPIO */
   pinMode(pin_yellow_led, OUTPUT);

   componentB1_init();
   componentB2_init();
   componentB3_init();
   componentB4_init();
   componentB5_init();
   componentB6_init();
}


void packageB_loop(void){
   /** Reset the state before calling all sub components */
   digitalWrite(pin_yellow_led, led_state_off);

   componentB1_loop();
   componentB2_loop();
   componentB3_loop();
   componentB4_loop();
   componentB5_loop();
   componentB6_loop();
}


void packageB_setU(int){
}


int packageB_getY(void){
	return 0;
}
