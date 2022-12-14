#include <stdio.h>

int main ()
{
	int step = 0;
	while (step++ < 5) {
	printf ("Step %3d:\n", step); 
	printf("%s %13s %14s %7s %5s %5s\n", 
		"List", "__PSW__", "PRI", "PID", "TICKS", "STATE");
	printf ("%s\n", "COMPLETED");
	printf ("%29s %3s %7s %5s %5s\n", "0x800012D6870004FF","128", "1234567", "4", "255");
	printf ("%s\n", "BLOCKED");
	printf ("%29s %3s %7s %5s %5s\n", "0x810012D688000480", "129", "1234568", "4", "128");
	printf ("%s\n", "READY");
	printf ("%29s %3s %7s %5s %5s\n", "0x200012D68A000302", "32", "1234567", "3", "2");
	printf ("%s\n", "RUNNING");
	printf ("%29s %3s %7s %5s %5s\n\n", "0x0000000000000401", "0", "0", "4", "1");
	}
	return 0;

}
