
#include <stdio.h>
#include "test.h"


int main(void) {
	void (**it) (void) = tests;
	
	while(*it) { (*it++)(); }

	return 0;
}
