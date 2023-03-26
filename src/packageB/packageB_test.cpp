#include <test.h>
#include "packageB.h"

#include <Arduino.h.stubs>


test_def(packageB_init){
   arduino.D[pin_yellow_led].mode = UINT8_MAX;
   packageB_init();
   ok(arduino.D[pin_yellow_led].mode == OUTPUT, "Init shall set GPIO mode to OUTPUT to drive the LED.");
}


test_def(packageB_loop){
	arduino.D[pin_yellow_led].value = UINT8_MAX;
	arduino.D[pin_yellow_button].value = button_state_released;
	packageB_loop();
	ok(arduino.D[pin_yellow_led].value == led_state_off, "");
}


test_def(packageB_setU){
	ok(1 == 1, "");
}


test_def(packageB_getY){
	ok(1 == 1, "");
}


test_def(packageB)
{
   test_call(packageB_init);
   test_call(packageB_loop);
   test_call(packageB_setU);
   test_call(packageB_getY);
}


test_entry(packageB);
test_main();
