#include <test.h>
#include "componentD1.h"

#include <Arduino.h.stubs>

test_def(componentD1_init){
   componentD1_init();
   ok(1 == 1, "");

}


test_def(componentD1_loop){
	componentD1_loop();
	ok(1 == 1, "");
}

 
test_def(componentD1_setU){
	ok(1 == 1, "");
}


test_def(componentD1_getY){
	ok(1 == 1, "");
}


test_def(comonentD1)
{
   test_call(componentD1_init);
   test_call(componentD1_loop);
   test_call(componentD1_setU);
   test_call(componentD1_getY);
}


test_entry(comonentD1);
test_main();
