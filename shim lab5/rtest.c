
/* AU21 CSE 2421 Lab 5 reverse test */

#include <stdio.h>
#include "l5.h"

int main()
{
	unsigned int x = 0x12345678u;

	printf("Reversing %x\n", x);
	x = rshim(x);
	printf("Reverse gave %x\n", x);

	return 0;
}
