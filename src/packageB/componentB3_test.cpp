#include <test.h>
#include "componentB3.h"

#include <Arduino.h.stubs>

test_def(componentB3_init){
   componentB3_init();
   ok(1 == 1, "");
}


test_def(componentB3_loop){
	componentB3_loop();
	ok(1 == 1, "");
}


test_def(componentB3_setU){
	ok(1 == 1, "");
}


test_def(componentB3_getY){
	ok(1 == 1, "");
}


test_def(comonentB3)
{
   test_call(componentB3_init);
   test_call(componentB3_loop);
   test_call(componentB3_setU);
   test_call(componentB3_getY);
}


test_entry(comonentB3);
test_main();
