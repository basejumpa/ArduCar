#include <test.h>
#include "componentB2.h"

#include <Arduino.h.stubs>

test_def(componentB2_init){
   ok(1 == 1, "");
}


test_def(componentB2_loop){
   arduino.D[pin_yellow_button].value = button_state_released;

   arduino.D[pin_yellow_led].value = UINT8_MAX;
   componentB2_loop();
   ok(arduino.D[pin_yellow_led].value == UINT8_MAX, "If button is released, then LED shall not be actuated.");


   arduino.D[pin_yellow_button].value = button_state_pressed;
   arduino.D[pin_yellow_led].value = UINT8_MAX;
   componentB2_loop();
   ok(arduino.D[pin_yellow_led].value == led_state_on, "If button is pressed, then LED shall be actuated.");
   arduino.D[pin_yellow_led].value = UINT8_MAX;
   componentB2_loop();
   ok(arduino.D[pin_yellow_led].value == UINT8_MAX, "A component shall never actuate the LED to off. This is done by package.");
   componentB2_loop();
   ok(arduino.D[pin_yellow_led].value == led_state_on, "");
   componentB2_loop();
   ok(arduino.D[pin_yellow_led].value == led_state_on, "");
}

test_def(componentB2_setU){
	ok(1 == 1, "");
}


test_def(componentB2_getY){
	ok(1 == 1, "");
}


test_def(comonentB2)
{
   test_call(componentB2_init);
   test_call(componentB2_loop);
   test_call(componentB2_setU);
   test_call(componentB2_getY);
}


test_entry(comonentB2);
test_main();
