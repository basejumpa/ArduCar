#include <test.h>
#include "packageA.h"

#include <Arduino.h.stubs>

test_def(packageA_init){
   arduino.D[pin_red_led].mode = UINT8_MAX;
   packageA_init();
   ok(arduino.D[pin_red_led].mode == OUTPUT, "Init shall set GPIO mode to OUTPUT to drive the LED.");
}


test_def(packageA_loop){
	arduino.D[pin_red_led].value = UINT8_MAX;
	arduino.D[pin_red_button].value = button_state_released;
	packageA_loop();
	ok(arduino.D[pin_red_led].value == led_state_off, "");
}


test_def(packageA_setU){
	ok(1 == 1, "");
}


test_def(packageA_getY){
	ok(1 == 1, "");
}


test_def(packageA)
{
   test_call(packageA_init);
   test_call(packageA_loop);
   test_call(packageA_setU);
   test_call(packageA_getY);
}


test_entry(packageA);
test_main();
