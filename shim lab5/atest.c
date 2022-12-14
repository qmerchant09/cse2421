

/* AU21 CSE 2421 Lab 5 adjust test */

#include <stdio.h>
#include "l5.h"

int main()
{
	unsigned int x = 0x12345678u, y = 0x55555555, broken, rev;

	broken = x + y;
	printf("Adjusting %x\n", broken);
	rev = ashim(broken);
	printf("Adjust gave %x\n", rev);

	return 0;
}
