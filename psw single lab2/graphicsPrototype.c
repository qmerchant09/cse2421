/* Quantez Merchant */
/* This file tests the graphics */

#include <stdio.h>
#include "libos.h"
#include "debug.h"
int main () {
int osValue = os_initialize(4);
int i;

if (TEXT || (GRAPHICS && osValue)){
	i = 0;
	while (i < 5) {
		os_clear(i);
		os_process(0,0,1234567,12345,1);
		os_refresh();
		getchar();
		i++;
	}
	os_teardown();
}
return 0;
}
