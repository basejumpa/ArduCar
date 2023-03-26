#include "packageC.h"
#include "componentC1.h"
#include "componentC2.h"
#include "componentC3.h"
#include "componentC4.h"
#include "componentC5.h"
#include "componentC6.h"


void packageC_init(void){
   /** Setup GPIO */
   pinMode(pin_blue_led, OUTPUT);

   componentC1_init();
   componentC2_init();
   componentC3_init();
   componentC4_init();
   componentC5_init();
   componentC6_init();
}


void packageC_loop(void){
   /** Reset the state before calling all sub components */
   digitalWrite(pin_blue_led, led_state_off);

   componentC1_loop();
   componentC2_loop();
   componentC3_loop();
   componentC4_loop();
   componentC5_loop();
   componentC6_loop();
}


void packageC_setU(int){
}


int packageC_getY(void){
	return 0;
}
