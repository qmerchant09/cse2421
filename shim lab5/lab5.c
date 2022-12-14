



/* AU21 CSE 2421 Lab 5 main */

#include <stdio.h>
#include "l5.h"

int main()
{
	unsigned int x = 0x12345678u, y = 0x55555555, broken, fixed;

	broken = x + y;
	printf("Lab5: All in one go: %x\n", broken);
	fixed = eshim(broken);
	printf("Everything gave %x\n", fixed);

	return 0;
}
