#include <test.h>
#include "componentC1.h"

#include <Arduino.h.stubs>

test_def(componentC1_init){
   componentC1_init();
	ok(1 == 1, "");
}


test_def(componentC1_loop){
	ok(1 == 1, "");
}

 
test_def(componentC1_setU){
	ok(1 == 1, "");
}


test_def(componentC1_getY){
	ok(1 == 1, "");
}


test_def(comonentC1)
{
   test_call(componentC1_init);
   test_call(componentC1_loop);
   test_call(componentC1_setU);
   test_call(componentC1_getY);
}


test_entry(comonentC1);
test_main();
