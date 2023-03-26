#include <test.h>
#include "componentB1.h"

#include <Arduino.h.stubs>

test_def(componentB1_init){
	ok(1 == 1, "");
}


test_def(componentB1_loop){
	ok(1 == 1, "");
}

 
test_def(componentB1_setU){
	ok(1 == 1, "");
}


test_def(componentB1_getY){
	ok(1 == 1, "");
}


test_def(comonentB1)
{
   test_call(componentB1_init);
   test_call(componentB1_loop);
   test_call(componentB1_setU);
   test_call(componentB1_getY);
}


test_entry(comonentB1);
test_main();
