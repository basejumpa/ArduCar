#include "packageE.h"
#include "componentE1.h"
#include "componentE2.h"
#include "componentE3.h"
#include "componentE4.h"
#include "componentE5.h"
#include "componentE6.h"


void packageE_init(void){
   /** Setup GPIO */
   pinMode(pin_white_led, OUTPUT);

   componentE1_init();
   componentE2_init();
   componentE3_init();
   componentE4_init();
   componentE5_init();
   componentE6_init();
}


void packageE_loop(void){
   /** Reset the state before calling all sub components */
   digitalWrite(pin_white_led, led_state_off);

   componentE1_loop();
   componentE2_loop();
   componentE3_loop();
   componentE4_loop();
   componentE5_loop();
   componentE6_loop();
}


void packageE_setU(int){
}


int packageE_getY(void){
	return 0;
}
