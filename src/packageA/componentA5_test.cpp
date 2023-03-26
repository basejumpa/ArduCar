#include <test.h>
#include "componentA5.h"

#include <Arduino.h.stubs>

test_def(componentA5_init){
   componentA5_init();
   ok(1 == 1, "");
}


test_def(componentA5_loop){
	componentA5_loop();
	ok(1 == 1, "");
}


test_def(componentA5_setU){
	ok(1 == 1, "");
}


test_def(componentA5_getY){
	ok(1 == 1, "");
}


test_def(comonentA5)
{
   test_call(componentA5_init);
   test_call(componentA5_loop);
   test_call(componentA5_setU);
   test_call(componentA5_getY);
}


test_entry(comonentA5);
test_main();
