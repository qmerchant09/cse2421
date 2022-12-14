/* Quantez Merchant */

#include <stdio.h>
#include "functions.h"
#include "debug.h"
#include "libos.h"
#define CORE 4

int main (){
	double start = now();
	int event = 0, step = 1;
	unsigned long currentPsw = 0, psw = 0;

	if (GRAPHICS && os_initialize(CORE)) {
		graphicsMode(event, currentPsw, psw, step, start);
	} else {
		textMode(event, currentPsw, psw, step, start);
	}
	terminate(start);

	return 0;
}
