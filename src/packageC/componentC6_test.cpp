#include <test.h>
#include "componentC6.h"

#include <Arduino.h.stubs>

test_def(componentC6_init){
	ok(1 == 1, "");
}


test_def(componentC6_loop){
	ok(1 == 1, "");
}


test_def(componentC6_setU){
	ok(1 == 1, "");
}


test_def(componentC6_getY){
	ok(1 == 1, "");
}


test_def(comonentC6)
{
   test_call(componentC6_init);
   test_call(componentC6_loop);
   test_call(componentC6_setU);
   test_call(componentC6_getY);
}


test_entry(comonentC6);
test_main();
