#include <test.h>
#include "componentC3.h"

#include <Arduino.h.stubs>

test_def(componentC3_init){
   ok(1 == 1, "");
}


test_def(componentC3_loop){
   arduino.D[pin_blue_button].value = button_state_released;

   arduino.D[pin_blue_led].value = UINT8_MAX;
   componentC3_loop();
   ok(arduino.D[pin_blue_led].value == UINT8_MAX, "If button is released, then LED shall not be actuated.");


   arduino.D[pin_blue_button].value = button_state_pressed;
   arduino.D[pin_blue_led].value = UINT8_MAX;
   componentC3_loop();
   ok(arduino.D[pin_blue_led].value == led_state_on, "If button is pressed, then LED shall be actuated.");
   arduino.D[pin_blue_led].value = UINT8_MAX;
   componentC3_loop();
   ok(arduino.D[pin_blue_led].value == UINT8_MAX, "A component shall never actuate the LED to off. This is done by package.");
   componentC3_loop();
   ok(arduino.D[pin_blue_led].value == led_state_on, "");
   componentC3_loop();
   ok(arduino.D[pin_blue_led].value == led_state_on, "");
}


test_def(componentC3_setU){
	ok(1 == 1, "");
}


test_def(componentC3_getY){
	ok(1 == 1, "");
}


test_def(comonentC3)
{
   test_call(componentC3_init);
   test_call(componentC3_loop);
   test_call(componentC3_setU);
   test_call(componentC3_getY);
}


test_entry(comonentC3);
test_main();
