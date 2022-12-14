/* Quantez Merchant */

/*This file contains functions that generate the output table */

#include <stdio.h>

/* This function creates the header for the output table */
int generateHeader () {
	printf ("STEP ");
	printf ("EVENT ");
	printf ("__PSW__            ");
	printf ("PRI     ");
	printf ("PID ");
	printf ("TICKS ");
	printf ("STATE\n");

	return 0;
}

/* This function fills the table with the specified information */
int generateRow (int step, int event, unsigned long psw, unsigned char pri, int pid, unsigned short ticks, unsigned char state) {
	printf ("%4d", step);
	printf ("%6d", event);
	printf (" 0x%016lX", psw);
	printf ("%4d", pri);
	printf ("%8d", pid);
	printf ("%6d", ticks);
	printf ("%6d\n", state);

	return 0;
}





