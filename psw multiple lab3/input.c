/* Quantez Merchant */

/* Changes from Professor Kirbys code */
/* Added two function calls to read_loop, changed the values passed to read_loop, added one job comments */
/* Copyright 2021 Neil Kirby. Not for disclosure */
#include <stdio.h>
#include <stdlib.h>
#include "utypes.h"

#include "debug.h"

#include "callbacks.h"
#include "structure.h"
#include "event.h"
#include "output.h"
#include "allocation.h"
#include "linkedlist.h"

/* This function processes one pass of the main loop */
void onepass (struct Simulation *s, int event, ulong riv) {
	int rval;
	rval = deleteSome(&s->complete,always_true, NULL, recycle_process,TEXT);
	if (DEBUG) printf("DEBUG: clear_complete: %d deleted.\n", rval);
	handle_event(s, event, riv);
	initial_output(++s->step);
	begin_output(s->step);
	master_output(s);
	finalize_output();
}

/* This function reads the values from the file and passes them to onepass */
void read_loop(struct Simulation *s) {
	int rval;
	int event;
	unsigned long riv;	/* read in value */
	
	while(2 == (rval = scanf("%d %lx", &event, &riv))) {
		if(DEBUG)printf("DEBUG: read_loop: read event %d, param %lX\n", event, riv);
	    	if( valid_event(event)) {
	    		onepass(s,event,riv);	
	    	} else {
	    		/* valid event complained for us */
			/* since we aren't failing to read, punch out from here so
		 	* that we don't have a scanf failed message. */
	    		return;
	    	}
	}
	if(TEXT)printf("Input terminated: scanf returned %d\n", rval);
	purge(s);
}

