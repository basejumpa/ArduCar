#include <test.h>
#include "componentA3.h"

#include <Arduino.h.stubs>

test_def(componentA3_init){
   componentA3_init();
   ok(1 == 1, "");
}


test_def(componentA3_loop){
	componentA3_loop();
	ok(1 == 1, "");
}


test_def(componentA3_setU){
	ok(1 == 1, "");
}


test_def(componentA3_getY){
	ok(1 == 1, "");
}


test_def(comonentA3)
{
   test_call(componentA3_init);
   test_call(componentA3_loop);
   test_call(componentA3_setU);
   test_call(componentA3_getY);
}


test_entry(comonentA3);
test_main();
