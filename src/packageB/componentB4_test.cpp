#include <test.h>
#include "componentB4.h"

#include <Arduino.h.stubs>


test_def(componentB4_init){
   componentB4_init();
   ok(1 == 1, "");
}


test_def(componentB4_loop){
	componentB4_loop();
	ok(1 == 1, "");
}


test_def(componentB4_setU){
	ok(1 == 1, "");
}


test_def(componentB4_getY){
	ok(1 == 1, "");
}


test_def(comonentB4)
{
   test_call(componentB4_init);
   test_call(componentB4_loop);
   test_call(componentB4_setU);
   test_call(componentB4_getY);
}


test_entry(comonentB4);
test_main();
