/* Quantez Merchant */
/* Changed init and teardown, added command line arguments */
/* Copyright 2021 Neil Kirby.  Not for disclosure */
#include <stdio.h>

#include "libos.h"
#include "debug.h"

#include "input.h"

#define COMMAND_LINE_NUMBER 2

/* This function initializes the file and mode */
int init(char *a[], FILE **fp)
{
	if((*fp = fopen(a[1],"r")) == NULL){
		if(TEXT)printf("ERROR: Unable to open %s for input.\n", a[1]);
		return 0;
	}
	if(TEXT)printf("DIAGNOSTIC: Successfully opened %s for input.\n",a[1]);
	return (TEXT || ( GRAPHICS && os_initialize(4)));
}

/* This function closes the file and ends the graphics */
void teardown(FILE *fp, char *a[])
{
	if(GRAPHICS)os_teardown();
	fclose(fp);
	if(TEXT)printf("DIAGNOSTIC: Closed input file %s.\n",a[1]);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	double start, runtime;
	if(argc == COMMAND_LINE_NUMBER)
	{
		start = now();
		if(init(argv,&fp))
		{
	    	run_sim(fp);
	    	teardown(fp,argv);
		}

		runtime = now()- start;
		printf("Total run time is %.9lf seconds.\n", runtime);
	}
	return(0);
}
