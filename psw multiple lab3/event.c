/* Quantez Merchant */

/* Changes from Professor Kirbys code */
/* Changed the code for all of the event functions, and turned the handle event function into a jump table, added one job comments */
/* Copyright 2021 Neil Kirby */

#include <stdio.h>
#include <stdlib.h>

#include "utypes.h"

#include "event_list.h"
#include "states.h"

#include "debug.h"

/* header files for functions bvelow here */
#include "psw.h"
#include "structure.h"
#include "allocation.h"
#include "callbacks.h"
#include "linkedlist.h"

/* individual event handlers up here, master event_handler at bottom */

/* This function processes the start event */
static void start_process(struct Simulation *s, ulong riv)
{
	struct Process *p;
	int rval;
	p = allocate_process(p);
	p->pid = ps_pid(riv);
	p->pri = ps_priority(riv);
	p->runtime = 0;
	p->ticks = 4;
	p->state = 2;
	p->sp = s;
	if(DEBUG)printf("DEBUG: start_process: creating PID %d priority %d\n", p->pid, p->pri);
	rval = insert(&s->ready,p,priority_order,TEXT);
	if (rval == 0) {
		recycle_process (p);
	}
	if(DEBUG)printf("DEBUG: start_process: success!\n");
} 

/* This function processes the end event */
static void end_process(struct Simulation *s, ulong riv)
{
	int pid = (int) riv;
	int rval;
	
	rval = deleteSome(&s->running, pid_matches, &pid, move_to_completed, TEXT);
	rval += deleteSome(&s->ready, pid_matches, &pid, move_to_completed, TEXT);
	rval += deleteSome(&s->blocked, pid_matches, &pid, move_to_completed, TEXT);
	if (rval != 1) {
		printf ("ERROR: end_process: %d instances of PID %d found.\n",rval,pid);
	}
	
} 

/* This function processes the time check event */
static void time_check(struct Simulation *s, ulong riv)
{
	int rval;
	iterate (s->running,dec_ticks);
	rval = deleteSome(&s->running, zero_ticks, NULL, move_to_ready, TEXT);
} 

/* This function processes the IO call event */
static void begin_IO(struct Simulation *s, ulong riv)
{
	int pid = (int) riv;
	int rval;
	rval = deleteSome(&s->running,pid_matches,&pid,move_to_blocked,TEXT);
	if (rval != 1) {
		printf ("ERROR: begin_IO: %d instances of PID %d found.\n",rval,pid);
	}
} 

/* This function processes the IO complete event */
static void end_IO(struct Simulation *s, ulong riv)
{
	int pid = (int) riv;
	int rval;
	rval = deleteSome(&s->blocked,pid_matches,&pid,move_to_ready,TEXT);
	if (rval != 1) {
		printf ("ERROR: end_IO: %d instances of PID %d found.\n",rval,pid);
	}
} 

/* This function processes the run event */
static void run_process(struct Simulation *s, ulong riv)
{
	int pid = (int) riv;
	int rval;
	rval = deleteSome(&s->ready, pid_matches, &pid, move_to_running, TEXT);
	if (rval != 1) {
		printf("ERROR: run_process: %d instances of PID %d found.\n",rval,pid);
	}
} 

/* public code below here */

/* This function determines the validity of an event */
int valid_event(int event)
{
	int rval = 0;
	switch (event)
	{
	    /* fallthrough intentional, all casses are good */
	    case E_START:
	    case E_END:
	    case E_TIME:
	    case E_IO_CALL:
	    case E_IO_COMPLETE:
	    case E_RUN:
	    	rval = 1;
		if(DEBUG)printf("DEBUG: valid_event: %d is good\n", event);
		break;
	    /* default means I don't know this event */
	    default:
if(TEXT)printf("ERROR: valid_event: %d is an invalid event. TERMINATING.\n",event);
	    	break;
	}
	return rval;

}

/* This function determines which event to process */
void handle_event(struct Simulation *s, int event, ulong riv)
{
	void (*eventJump[6]) (struct Simulation*, ulong) = {start_process,end_process,time_check,begin_IO,end_IO,run_process};	
	
	 eventJump[event] (s,riv);
}

