#include <test.h>
#include "componentE4.h"

#include <Arduino.h.stubs>

test_def(componentE4_init){
   componentE4_init();
   ok(1 == 1, "");
}


test_def(componentE4_loop){
	componentE4_loop();
	ok(1 == 1, "");
}


test_def(componentE4_setU){
	ok(1 == 1, "");
}


test_def(componentE4_getY){
	ok(1 == 1, "");
}


test_def(comonentE4)
{
   test_call(componentE4_init);
   test_call(componentE4_loop);
   test_call(componentE4_setU);
   test_call(componentE4_getY);
}


test_entry(comonentE4);
test_main();
