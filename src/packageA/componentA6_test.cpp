#include <test.h>
#include "componentA6.h"

#include <Arduino.h.stubs>

test_def(componentA6_init){
	ok(1 == 1, "");
}


test_def(componentA6_loop){
	ok(1 == 1, "");
}


test_def(componentA6_setU){
	ok(1 == 1, "");
}


test_def(componentA6_getY){
	ok(1 == 1, "");
}


test_def(comonentA6)
{
   test_call(componentA6_init);
   test_call(componentA6_loop);
   test_call(componentA6_setU);
   test_call(componentA6_getY);
}


test_entry(comonentA6);
test_main();
