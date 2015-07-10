
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#include "test.h"


void test1(void) {
	uint32_t* buff = malloc(sizeof(Msg));
	Msg* msg = (Msg*)(buff);

	for (int i = 0; i < 10; i++) {
		msg->a = i;
		msg->b = i+1;
		
		printf("buff[0]: %u, buff[1]: %u\n",
		       buff[0], buff[1]);
	}
}

void test2(void) {
        float a = 4.12345f;

	// dereferencing type-punned pointer -> break the strict-aliasing rules
	unsigned int temp = *(unsigned int *)&a;
	temp &= 0x7fffffff;
	// again
	printf("%f\n", *(float *)&temp);
}

void test3(void) {
	float f = -0.1;
	unsigned int *ui = (unsigned int*) &f;
	printf("%f is lower than 0? -> %s\n", f,
	       (*ui & 0x80000000)? "true":"false");
}

void test4(void) {
	union a_union t;
	t.d = 3.12345;
	printf("t.d=3.0 -> t.i: %d\n", t.i);
}

void test5(void) {
	union a_union t;
	int* ip;
	t.d = 3.12345;
	ip = &t.i;
	printf("t.d=3.0 -> *ip: %d\n", *ip);
}

void test6(void) {
	float d = 3.12345;
	printf("%d\n", ((union a_union*) &d)->i);
}


void (*tests[]) (void) = {
	test1,
	test2,
	test3,
	test4,
	test5,
	test6,
	0
};
