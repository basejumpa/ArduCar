#include <test.h>
#include "componentC2.h"

#include <Arduino.h.stubs>

test_def(componentC2_init){
   componentC2_init();
   ok(1 == 1, "");
}


test_def(componentC2_loop){
	componentC2_loop();
	ok(1 == 1, "");
}


test_def(componentC2_setU){
	ok(1 == 1, "");
}


test_def(componentC2_getY){
	ok(1 == 1, "");
}


test_def(comonentC2)
{
   test_call(componentC2_init);
   test_call(componentC2_loop);
   test_call(componentC2_setU);
   test_call(componentC2_getY);
}


test_entry(comonentC2);
test_main();
