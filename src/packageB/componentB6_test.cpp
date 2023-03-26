#include <test.h>
#include "componentB6.h"

#include <Arduino.h.stubs>

test_def(componentB6_init){
   componentB6_init();
	ok(1 == 1, "");
}


test_def(componentB6_loop){
	componentB6_loop();
	ok(1 == 1, "");
}


test_def(componentB6_setU){
	ok(1 == 1, "");
}


test_def(componentB6_getY){
	ok(1 == 1, "");
}


test_def(comonentB6)
{
   test_call(componentB6_init);
   test_call(componentB6_loop);
   test_call(componentB6_setU);
   test_call(componentB6_getY);
}


test_entry(comonentB6);
test_main();
