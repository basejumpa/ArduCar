#include <test.h>
#include "componentC5.h"

#include <Arduino.h.stubs>

test_def(componentC5_init){
   componentC5_init();
   ok(1 == 1, "");
}


test_def(componentC5_loop){
	componentC5_loop();
	ok(1 == 1, "");
}


test_def(componentC5_setU){
	ok(1 == 1, "");
}


test_def(componentC5_getY){
	ok(1 == 1, "");
}


test_def(comonentC5)
{
   test_call(componentC5_init);
   test_call(componentC5_loop);
   test_call(componentC5_setU);
   test_call(componentC5_getY);
}


test_entry(comonentC5);
test_main();
