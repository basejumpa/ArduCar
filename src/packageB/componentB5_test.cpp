#include <test.h>
#include "componentB5.h"

#include <Arduino.h.stubs>

test_def(componentB5_init){
   componentB5_init();
   ok(1 == 1, "");
}


test_def(componentB5_loop){
	componentB5_loop();
	ok(1 == 1, "");
}


test_def(componentB5_setU){
	ok(1 == 1, "");
}


test_def(componentB5_getY){
	ok(1 == 1, "");
}


test_def(comonentB5)
{
   test_call(componentB5_init);
   test_call(componentB5_loop);
   test_call(componentB5_setU);
   test_call(componentB5_getY);
}


test_entry(comonentB5);
test_main();
