#include <test.h>
#include "packageE.h"

#include <Arduino.h.stubs>

test_def(packageE_init){
   arduino.D[pin_white_led].mode = UINT8_MAX;
   packageE_init();
   ok(arduino.D[pin_white_led].mode == OUTPUT, "Init shall set GPIO mode to OUTPUT to drive the LED.");
}


test_def(packageE_loop){
	arduino.D[pin_white_led].value = UINT8_MAX;
	arduino.D[pin_white_button].value = button_state_released;
	packageE_loop();
	ok(arduino.D[pin_white_led].value == led_state_off, "");
}


test_def(packageE_setU){
	ok(1 == 1, "");
}


test_def(packageE_getY){
	ok(1 == 1, "");
}


test_def(packageE)
{
   test_call(packageE_init);
   test_call(packageE_loop);
   test_call(packageE_setU);
   test_call(packageE_getY);
}


test_entry(packageE);
test_main();
