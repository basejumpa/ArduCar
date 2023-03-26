#include <test.h>
#include "componentD4.h"

#include <Arduino.h.stubs>

test_def(componentD4_init){
   ok(1 == 1, "");
}


test_def(componentD4_loop){
   arduino.D[pin_green_button].value = button_state_released;

   arduino.D[pin_green_led].value = UINT8_MAX;
   componentD4_loop();
   ok(arduino.D[pin_green_led].value == UINT8_MAX, "If button is released, then LED shall not be actuated.");


   arduino.D[pin_green_button].value = button_state_pressed;
   arduino.D[pin_green_led].value = UINT8_MAX;
   componentD4_loop();
   ok(arduino.D[pin_green_led].value == led_state_on, "If button is pressed, then LED shall be actuated.");
   arduino.D[pin_green_led].value = UINT8_MAX;
   componentD4_loop();
   ok(arduino.D[pin_green_led].value == UINT8_MAX, "A component shall never actuate the LED to off. This is done by package.");
   componentD4_loop();
   ok(arduino.D[pin_green_led].value == led_state_on, "");
   componentD4_loop();
   ok(arduino.D[pin_green_led].value == led_state_on, "");
}


test_def(componentD4_setU){
	ok(1 == 1, "");
}


test_def(componentD4_getY){
	ok(1 == 1, "");
}


test_def(comonentD4)
{
   test_call(componentD4_init);
   test_call(componentD4_loop);
   test_call(componentD4_setU);
   test_call(componentD4_getY);
}


test_entry(comonentD4);
test_main();
