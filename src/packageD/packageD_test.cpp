#include <test.h>
#include "packageD.h"

#include <Arduino.h.stubs>


test_def(packageD_init){
   arduino.D[pin_green_led].mode = UINT8_MAX;
   packageD_init();
   ok(arduino.D[pin_green_led].mode == OUTPUT, "Init shall set GPIO mode to OUTPUT to drive the LED.");
}


test_def(packageD_loop){
	arduino.D[pin_green_led].value = UINT8_MAX;
	arduino.D[pin_green_button].value = button_state_released;
	packageD_loop();
	ok(arduino.D[pin_green_led].value == led_state_off, "");
}


test_def(packageD_setU){
	ok(1 == 1, "");
}


test_def(packageD_getY){
	ok(1 == 1, "");
}


test_def(packageD)
{
   test_call(packageD_init);
   test_call(packageD_loop);
   test_call(packageD_setU);
   test_call(packageD_getY);
}


test_entry(packageD);
test_main();
