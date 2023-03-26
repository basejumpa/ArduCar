#include "config.h"
#include "packageA/packageA.h"
#include "packageB/packageB.h"
#include "packageC/packageC.h"
#include "packageD/packageD.h"
#include "packageE/packageE.h"

static const long deltaT_ms = CFG_DELTA_T_MS;
static long previousMillis = 0;


void setup(void){
   Serial.begin(57600);

   pinMode(pin_red_button,    INPUT_PULLUP);
   pinMode(pin_yellow_button, INPUT_PULLUP);
   pinMode(pin_blue_button,   INPUT_PULLUP);
   pinMode(pin_green_button,  INPUT_PULLUP);
   pinMode(pin_white_button,  INPUT_PULLUP);

   pinMode(pin_buzzer, OUTPUT);

   packageA_init();
   packageB_init();
   packageC_init();
   packageD_init();
   packageE_init();
}


static void mainloop(void){
   /** Reset the state before calling all sub components */
   digitalWrite(pin_buzzer, led_state_off);

   packageA_loop();
   packageB_loop();
   packageC_loop();
   packageD_loop();
   packageE_loop();
}


void loop(void){
   unsigned long currentMillis = millis();
   if(currentMillis - previousMillis > deltaT_ms) {
    previousMillis = currentMillis;   
	mainloop();
  }
}

int app_getDeltaT_ms(void){
	return (int)deltaT_ms;
}
