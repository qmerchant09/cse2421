/* Quantez Merchant */

/* Changes to Professor Kirbys code */
/* Added a structure initialization to main, added one job comments */
/* Copyright 2021 Neil Kirby.  Not for disclosure */
#include <stdio.h>

#include "libos.h"
#include "debug.h"

#include "structure.h"
#include "utypes.h"
#include "input.h"

/* This function initializes the graphics if in graphics mode */
int init()
{
	return (TEXT || ( GRAPHICS && os_initialize(4)));
}

/* This function tears down the graphics if in graphics mode */
void teardown()
{
	if(GRAPHICS)os_teardown();
}


int main()
{
	double start, runtime;

	start = now();
	if(init())
	{
	    struct Simulation s;
	    s.step = 0;
	    s.complete = NULL;
	    s.blocked = NULL;
	    s.ready = NULL;
	    s.running = NULL;
	    read_loop(&s);
	    teardown();
	}


	runtime = now()- start;
	printf("Total run time is %.9lf seconds.\n", runtime);


	return(0);
}
