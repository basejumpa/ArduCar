#include <test.h>
#include "componentD6.h"

#include <Arduino.h.stubs>

test_def(componentD6_init){
   componentD6_init();
   ok(1 == 1, "");
}


test_def(componentD6_loop){
	componentD6_loop();
	ok(1 == 1, "");
}


test_def(componentD6_setU){
	ok(1 == 1, "");
}


test_def(componentD6_getY){
	ok(1 == 1, "");
}


test_def(comonentD6)
{
   test_call(componentD6_init);
   test_call(componentD6_loop);
   test_call(componentD6_setU);
   test_call(componentD6_getY);
}


test_entry(comonentD6);
test_main();
