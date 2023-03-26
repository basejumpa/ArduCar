#include <test.h>
#include "componentE5.h"

#include <Arduino.h.stubs>


test_def(componentE5_init){
   ok(1 == 1, "");
}


test_def(componentE5_loop){
   arduino.D[pin_white_button].value = button_state_released;

   arduino.D[pin_white_led].value = UINT8_MAX;
   componentE5_loop();
   ok(arduino.D[pin_white_led].value == UINT8_MAX, "If button is released, then LED shall not be actuated.");


   arduino.D[pin_white_button].value = button_state_pressed;
   arduino.D[pin_white_led].value = UINT8_MAX;
   componentE5_loop();
   ok(arduino.D[pin_white_led].value == led_state_on, "If button is pressed, then LED shall be actuated.");
   arduino.D[pin_white_led].value = UINT8_MAX;
   componentE5_loop();
   ok(arduino.D[pin_white_led].value == UINT8_MAX, "A component shall never actuate the LED to off. This is done by package.");
   componentE5_loop();
   ok(arduino.D[pin_white_led].value == led_state_on, "");
   componentE5_loop();
   ok(arduino.D[pin_white_led].value == led_state_on, "");
}


test_def(componentE5_setU){
	ok(1 == 1, "");
}


test_def(componentE5_getY){
	ok(1 == 1, "");
}


test_def(comonentE5)
{
   test_call(componentE5_init);
   test_call(componentE5_loop);
   test_call(componentE5_setU);
   test_call(componentE5_getY);
}


test_entry(comonentE5);
test_main();
