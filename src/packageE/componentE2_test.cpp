#include <test.h>
#include "componentE2.h"

#include <Arduino.h.stubs>

test_def(componentE2_init){
   componentE2_init();
   ok(1 == 1, "");
}


test_def(componentE2_loop){
	componentE2_loop();
	ok(1 == 1, "");
}


test_def(componentE2_setU){
	ok(1 == 1, "");
}


test_def(componentE2_getY){
	ok(1 == 1, "");
}


test_def(comonentE2)
{
   test_call(componentE2_init);
   test_call(componentE2_loop);
   test_call(componentE2_setU);
   test_call(componentE2_getY);
}


test_entry(comonentE2);
test_main();
