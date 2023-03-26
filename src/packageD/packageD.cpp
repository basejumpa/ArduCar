#include "packageD.h"
#include "componentD1.h"
#include "componentD2.h"
#include "componentD3.h"
#include "componentD4.h"
#include "componentD5.h"
#include "componentD6.h"


void packageD_init(void){
   /** Setup GPIO */
   pinMode(pin_green_led, OUTPUT);

   componentD1_init();
   componentD2_init();
   componentD3_init();
   componentD4_init();
   componentD5_init();
   componentD6_init();
}


void packageD_loop(void){
   /** Reset the state before calling all sub components */
   digitalWrite(pin_green_led, led_state_off);

   componentD1_loop();
   componentD2_loop();
   componentD3_loop();
   componentD4_loop();
   componentD5_loop();
   componentD6_loop();
}


void packageD_setU(int){
}


int packageD_getY(void){
	return 0;
}
