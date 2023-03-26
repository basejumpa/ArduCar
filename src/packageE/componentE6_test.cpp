#include <test.h>
#include "componentE6.h"

#include <Arduino.h.stubs>

test_def(componentE6_init){
   componentE6_init();
	ok(1 == 1, "");
}


test_def(componentE6_loop){
   componentE6_loop();
	ok(1 == 1, "");
}


test_def(componentE6_setU){
	ok(1 == 1, "");
}


test_def(componentE6_getY){
	ok(1 == 1, "");
}


test_def(comonentE6)
{
   test_call(componentE6_init);
   test_call(componentE6_loop);
   test_call(componentE6_setU);
   test_call(componentE6_getY);
}


test_entry(comonentE6);
test_main();
