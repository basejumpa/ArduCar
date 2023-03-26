#include <test.h>
#include "componentA1.h"

#include <Arduino.h.stubs>


test_def(componentA1_init){
   ok(1 == 1, "");
}


test_def(componentA1_loop){
   arduino.D[pin_red_button].value = button_state_released;

   arduino.D[pin_red_led].value = UINT8_MAX;
   componentA1_loop();
   ok(arduino.D[pin_red_led].value == UINT8_MAX, "If button is released, then LED shall not be actuated.");


   arduino.D[pin_red_button].value = button_state_pressed;
   arduino.D[pin_red_led].value = UINT8_MAX;
   componentA1_loop();
   ok(arduino.D[pin_red_led].value == led_state_on, "If button is pressed, then LED shall be actuated.");
   arduino.D[pin_red_led].value = UINT8_MAX;
   componentA1_loop();
   ok(arduino.D[pin_red_led].value == UINT8_MAX, "A component shall never actuate the LED to off. This is done by package.");
   componentA1_loop();
   ok(arduino.D[pin_red_led].value == led_state_on, "");
   componentA1_loop();
   ok(arduino.D[pin_red_led].value == led_state_on, "");
}

 
test_def(componentA1_setU){
	ok(1 == 1, "");
}


test_def(componentA1_getY){
	ok(1 == 1, "");
}


test_def(comonentA1)
{
   test_call(componentA1_init);
   test_call(componentA1_loop);
   test_call(componentA1_setU);
   test_call(componentA1_getY);
}


test_entry(comonentA1);
test_main();
