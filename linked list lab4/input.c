/* Quantez Merchant */
/* Changed the function header of run_sim and changes scanf to fscanf */ 
/* Copyright 2021 Neil Kirby. Not for disclosure */
#include <stdio.h>

#include "utypes.h"
#include "debug.h"
#include "structs.h"

#include "event.h"
#include "output.h"

/* This function reads the values from the input file and runs event handler and output */
static void read_loop(struct Sim *sp)
{
	int rval;
	int event;
	unsigned long riv;	/* read in value */

	while(2 == (rval = fscanf(sp->fp,"%d %lx", &event, &riv)))
	{
if(DEBUG)printf("DEBUG: read_loop: read event %d, param %lX\n", event, riv);
	    if( valid_event(event))
	    {
	    	sp->step++;
		clear_completed(sp);
	    	handle_event(sp, event, riv);
		master_output(sp);
	    }
	    else
	    {
	    	/* valid event complained for us */
		/* since we aren't failing to read, punch out from here so
		 * that we don't have a scanf failed message. */
	    	break;
	    }
	}
	if(rval != 2)if(TEXT)printf("Input terminated: scanf returned %d\n", rval);
	purge(sp);

}

/* This function creates the simulation */
void run_sim(FILE *fp)
{
	/* create a new sim ...*/
	struct Sim cylon = { 0, NULL, NULL, NULL, NULL,NULL};
	struct Sim *sp = &cylon;
	sp->fp = fp;
	/* ...and run it */
	read_loop(sp);

}

