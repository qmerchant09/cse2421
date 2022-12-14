/* Quantez Merchant */
/*Changed the calloc and free calls to alternative*/
/* Copyright 2021 Neil Kirby.  Not for distribution */

#include <stdlib.h>
#include <stdio.h>

#include "altmem.h"
#include "debug.h"
#include "structs.h"

/* This function allocates a process */
struct Proc *allocate_process()
{
	struct Proc *pp= NULL;
	static int acount = 0;

	if (pp = alternative_calloc(1, sizeof(struct Proc)))
	{
	    acount++;
	    if(TEXT)printf("DIAGNOSTIC: allocate_process.  %d allocated so far.\n", acount);
	}
	else
	{
	    if(TEXT)printf("ERROR: allocate_process: calloc failed\n");
	}
	return pp;
}

/* This function frees a process */
void recycle_process(void *data)
{
	struct Proc *pp = data;
	static int rcount = 0;

	if(pp)
	{
	    rcount++;
if(TEXT)printf("DIAGNOSTIC: recycle_process on PID %d which ran %d.  %d freed\n", 
		pp->pid, pp->runtime, rcount);
	    alternative_free(pp);
	}
	else
	{
	    if(TEXT)printf("ERROR: recycle_process given NULL\n");
	}
}
