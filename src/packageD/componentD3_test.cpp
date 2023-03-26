#include <test.h>
#include "componentD3.h"

#include <Arduino.h.stubs>

test_def(componentD3_init){
   componentD3_init();
   ok(1 == 1, "");
}


test_def(componentD3_loop){
	componentD3_loop();
	ok(1 == 1, "");
}


test_def(componentD3_setU){
	ok(1 == 1, "");
}


test_def(componentD3_getY){
	ok(1 == 1, "");
}


test_def(comonentD3)
{
   test_call(componentD3_init);
   test_call(componentD3_loop);
   test_call(componentD3_setU);
   test_call(componentD3_getY);
}


test_entry(comonentD3);
test_main();
