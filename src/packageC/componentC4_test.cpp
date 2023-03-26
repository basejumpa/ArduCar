#include <test.h>
#include "componentC4.h"

#include <Arduino.h.stubs>

test_def(componentC4_init){
   componentC4_init();
   ok(1 == 1, "");
}


test_def(componentC4_loop){
	componentC4_loop();
	ok(1 == 1, "");
}


test_def(componentC4_setU){
	ok(1 == 1, "");
}


test_def(componentC4_getY){
	ok(1 == 1, "");
}


test_def(comonentC4)
{
   test_call(componentC4_init);
   test_call(componentC4_loop);
   test_call(componentC4_setU);
   test_call(componentC4_getY);
}


test_entry(comonentC4);
test_main();
