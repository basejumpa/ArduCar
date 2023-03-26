#include <test.h>
#include "packageC.h"

#include <Arduino.h.stubs>

test_def(packageC_init){
   arduino.D[pin_blue_led].mode = UINT8_MAX;
   packageC_init();
   ok(arduino.D[pin_blue_led].mode == OUTPUT, "Init shall set GPIO mode to OUTPUT to drive the LED.");
}


test_def(packageC_loop){
	arduino.D[pin_blue_led].value = UINT8_MAX;
	arduino.D[pin_blue_button].value = button_state_released;
	packageC_loop();
	ok(arduino.D[pin_blue_led].value == led_state_off, "");
}


test_def(packageC_setU){
	ok(1 == 1, "");
}


test_def(packageC_getY){
	ok(1 == 1, "");
}


test_def(packageC)
{
   test_call(packageC_init);
   test_call(packageC_loop);
   test_call(packageC_setU);
   test_call(packageC_getY);
}


test_entry(packageC);
test_main();
