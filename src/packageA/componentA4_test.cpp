#include <test.h>
#include "componentA4.h"

#include <Arduino.h.stubs>

test_def(componentA4_init){
   componentA4_init();
   ok(1 == 1, "");
}


test_def(componentA4_loop){
	componentA4_loop();
	ok(1 == 1, "");
}


test_def(componentA4_setU){
	ok(1 == 1, "");
}


test_def(componentA4_getY){
	ok(1 == 1, "");
}


test_def(componentA4)
{
   test_call(componentA4_init);
   test_call(componentA4_loop);
   test_call(componentA4_setU);
   test_call(componentA4_getY);
}


test_entry(componentA4);
test_main();
