#include <test.h>
#include "componentA2.h"

#include <Arduino.h.stubs>

test_def(componentA2_init){
   componentA2_init();
   ok(1 == 1, "");
}


test_def(componentA2_loop){
	componentA2_loop();
	ok(1 == 1, "");
}


test_def(componentA2_setU){
	ok(1 == 1, "");
}


test_def(componentA2_getY){
	ok(1 == 1, "");
}


test_def(comonentA2)
{
   test_call(componentA2_init);
   test_call(componentA2_loop);
   test_call(componentA2_setU);
   test_call(componentA2_getY);
}


test_entry(comonentA2);
test_main();
