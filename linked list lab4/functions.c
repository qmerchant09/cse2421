
/* Copyright 2021 Neil Kirby, not for distribution */

#include <stdio.h>

#include "linkedlist.h"
#include "debug.h"
#include "structs.h"

#include "dynamic.h"


/* comparison functions */

/* This function sorts the list into priority order */
int priority_order( void *data1, void *data2)
{
	struct Proc *pp1 = data1, *pp2 = data2;

	return( pp1->priority < pp2->priority);
}


/* criteria functions */

/* This function returns true*/
int always_true(void *data, void *helper)
{
	return 1;
}

/* This function determines if the helper matches the process data */
int pid_matches(void *data, void *helper)
{
	struct Proc *pp = data;
	int *ip = helper;

	return (pp->pid == *ip); 
}

/* This function determines if a process has zero ticks */
int zero_ticks(void *data, void *helper)
{
	struct Proc *pp = data;

	return(pp->ticks ==0);
}
	


/* Action functions */

/* This function decreases the ticks and increases the runtime */
void dec_ticks(void *data)
{
	struct Proc *pp = data;

	if(pp->ticks)pp->ticks--;
	pp->runtime++;
}

