#include <test.h>
#include "componentE3.h"

#include <Arduino.h.stubs>

test_def(componentE3_init){
   componentE3_init();
   ok(1 == 1, "");
}


test_def(componentE3_loop){
	componentE3_loop();
	ok(1 == 1, "");
}


test_def(componentE3_setU){
	ok(1 == 1, "");
}


test_def(componentE3_getY){
	ok(1 == 1, "");
}


test_def(comonentE3)
{
   test_call(componentE3_init);
   test_call(componentE3_loop);
   test_call(componentE3_setU);
   test_call(componentE3_getY);
}


test_entry(comonentE3);
test_main();
