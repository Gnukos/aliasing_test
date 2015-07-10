

#ifndef __TEST_H
#define __TEST_H

extern void (*tests[]) (void);

typedef struct Msg {
	unsigned int a;
	unsigned int b;
} Msg;

union a_union {
	int i;
	float d;
};

#endif
