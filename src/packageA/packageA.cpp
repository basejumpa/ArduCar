#include "packageA.h"
#include "componentA1.h"
#include "componentA2.h"
#include "componentA3.h"
#include "componentA4.h"
#include "componentA5.h"
#include "componentA6.h"


void packageA_init(void){
   /** Setup GPIO */
   pinMode(pin_red_led, OUTPUT);

   componentA1_init();
   componentA2_init();
   componentA3_init();
   componentA4_init();
   componentA5_init();
   componentA6_init();
}


void packageA_loop(void){
   /** Reset the state before calling all sub components */
   digitalWrite(pin_red_led, buzzer_state_off);

   componentA1_loop();
   componentA2_loop();
   componentA3_loop();
   componentA4_loop();
   componentA5_loop();
   componentA6_loop();
}


void packageA_setU(int){
}


int packageA_getY(void){
	return 0;
}
