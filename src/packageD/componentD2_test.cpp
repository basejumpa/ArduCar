#include <test.h>
#include "componentD2.h"

#include <Arduino.h.stubs>

test_def(componentD2_init){
   componentD2_init();
   ok(1 == 1, "");
}


test_def(componentD2_loop){
	componentD2_loop();
	ok(1 == 1, "");
}


test_def(componentD2_setU){
	ok(1 == 1, "");
}


test_def(componentD2_getY){
	ok(1 == 1, "");
}


test_def(comonentD2)
{
   test_call(componentD2_init);
   test_call(componentD2_loop);
   test_call(componentD2_setU);
   test_call(componentD2_getY);
}


test_entry(comonentD2);
test_main();
