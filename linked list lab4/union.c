
#include <stdio.h>

#include "Param.h"

int main()
{
	union Param riv;

	riv.psw = 0x0102030405060708L;

	printf(" In the union psw= 0x%lX and pid = 0x%0x\n", riv.psw, riv.pid);

	riv.pid = 1;

	printf("In the union, pid = %d and psw = %lx\n", riv.pid, riv.psw);

    return 0;
}

