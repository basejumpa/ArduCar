#include <test.h>
#include "componentD5.h"

#include <Arduino.h.stubs>

test_def(componentD5_init){
   componentD5_init();
   ok(1 == 1, "");
}


test_def(componentD5_loop){
	componentD5_loop();
	ok(1 == 1, "");
}


test_def(componentD5_setU){
	ok(1 == 1, "");
}


test_def(componentD5_getY){
	ok(1 == 1, "");
}


test_def(comonentD5)
{
   test_call(componentD5_init);
   test_call(componentD5_loop);
   test_call(componentD5_setU);
   test_call(componentD5_getY);
}


test_entry(comonentD5);
test_main();
