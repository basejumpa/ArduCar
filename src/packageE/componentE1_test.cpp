#include <test.h>
#include "componentE1.h"

#include <Arduino.h.stubs>

test_def(componentE1_init){
   componentE1_init();
   ok(1 == 1, "");
}


test_def(componentE1_loop){
	ok(1 == 1, "");
}

 
test_def(componentE1_setU){
	ok(1 == 1, "");
}


test_def(componentE1_getY){
	ok(1 == 1, "");
}


test_def(comonentE1)
{
   test_call(componentE1_init);
   test_call(componentE1_loop);
   test_call(componentE1_setU);
   test_call(componentE1_getY);
}


test_entry(comonentE1);
test_main();
