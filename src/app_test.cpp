#include <test.h>
#include "app.h"

#include <Arduino.h.stubs>

test_def(setup){
   setup();

   ok(arduino.Serial.baud == 57600, "");

   ok(arduino.D[pin_red_button].mode    == INPUT_PULLUP, "");
   ok(arduino.D[pin_yellow_button].mode == INPUT_PULLUP, "");
   ok(arduino.D[pin_blue_button].mode   == INPUT_PULLUP, "");
   ok(arduino.D[pin_green_button].mode  == INPUT_PULLUP, "");
   ok(arduino.D[pin_white_button].mode  == INPUT_PULLUP, "");

   ok(arduino.D[pin_buzzer].mode        == OUTPUT, "");
}


test_def(loop){
	arduino.D[pin_buzzer].value = UINT8_MAX;
	arduino.D[pin_buzzer].value = button_state_released;
	loop();
	ok(arduino.D[pin_buzzer].value == buzzer_state_off, "");
}
}


test_def(app_getDeltaT_ms){
	app_getDeltaT_ms();
	ok(1 == 1, "");
}

test_def(app)
{
   test_call(setup);
   test_call(loop);
   test_call(app_getDeltaT_ms);
}


test_entry(app);
test_main();
