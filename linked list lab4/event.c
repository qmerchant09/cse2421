
/* Copyright 2021 Neil Kirby.  Not for disclosure */
#include <stdio.h>

#include "utypes.h"
#include "structs.h"

#include "event_list.h"
#include "states.h"

#include "debug.h"

/* header files for functions bvelow here */
#include "psw.h"
#include "dynamic.h"
#include "functions.h"
#include "linkedlist.h"

/* event-related action functions need to be here */

/* This function moves an element to a new list */
void move_to(void *aoh, struct Proc *pp, char *list_name)
{
	
	/* we are falling off another list, try to toss onto completed */
	if( insert( aoh, pp, priority_order, TEXT))
	{
    if(DEBUG)printf("DEBUG: move_to_%s for PID %d\n", list_name,  pp->pid);
	}
	else
	{
if(TEXT)printf("ERROR: move_to_%s: unable to move PID %d\n", list_name, pp->pid);
	    recycle_process(pp);
	}
}

/* This function tells move_to to add to the running list */
void move_to_running(void *data)
{
	struct Proc *pp = data;

	move_to( &pp->system->running, pp, "running");
	pp->state = RUNNING;
	pp->ticks = DEFAULT_TICKS;
}

/* This function tells move_to to add to the blocked list */
void move_to_blocked(void *data)
{
	struct Proc *pp = data;

	move_to( &pp->system->blocked, pp, "blocked");
	pp->state = BLOCKED;
}

/* This function tells move_to to add to the ready list */
void move_to_ready(void *data)
{
	struct Proc *pp = data;

	move_to( &pp->system->ready, pp, "ready");
	pp->state = READY;
}

/* This function tells move_to to add to the completed list */
void move_to_completed(void *data)
{
	struct Proc *pp = data;

	move_to( &pp->system->completed, pp, "completed");
	pp->state = COMPLETE;
}

/* not an event but kind of like one */
/* This function clears the competed list */
void clear_completed(struct Sim *sp)
{
	int i;

i = deleteSome(&sp->completed, always_true, NULL, recycle_process, TEXT);
    	if(DEBUG)printf("DEBUG: clear_completed: %d deleted.\n", i);
}

/* This function deletes everything on all lists */
void purge(struct Sim *sp)
{
	int i;
i = deleteSome(&sp->completed, always_true, NULL, recycle_process, TEXT);
    	if(DEBUG)printf("DEBUG: purge: Completed: %d deleted.\n", i);
i = deleteSome(&sp->blocked, always_true, NULL, recycle_process, TEXT);
    	if(DEBUG)printf("DEBUG: purge: blocked: %d deleted.\n", i);
i = deleteSome(&sp->ready, always_true, NULL, recycle_process, TEXT);
    	if(DEBUG)printf("DEBUG: purge: ready: %d deleted.\n", i);
i = deleteSome(&sp->running, always_true, NULL, recycle_process, TEXT);
    	if(DEBUG)printf("DEBUG: purge: running: %d deleted.\n", i);

}


/* have all of the event handlers have the same signature so that in lab 3
 * they can be in a jump table.  They take a psw and the Read In Value
 * (riv)  */

/* individual event handleers up here, master event_handler at bottom */

/* This function adds data to a new process */
static void load_proc_data(struct Sim *sp, struct Proc *pp, ulong riv)
{
	/* load all the members of a new process */
	pp->system = sp;
	pp->runtime = 0;
	/* I was given a psw */
	pp->pid = ps_pid(riv);
	pp->priority = ps_priority(riv);
	pp->state = READY;
	pp->ticks = DEFAULT_TICKS;

}


/* This function processes the start event */
static void start_process(struct Sim *sp, ulong riv)
{
	struct Proc *pp;

	if(pp = allocate_process())
	{
	    load_proc_data(sp, pp, riv);
if(DEBUG)printf("DEBUG: start_process: creating PID %d priority %d\n", 
		pp->pid, pp->priority);
	    if( insert(&sp->ready, pp, priority_order, TEXT))
	    {
	    	if(DEBUG)printf("DEBUG: start_process: success!\n");
	    }
	    else
	    {
if(TEXT)printf("Error: start_process: insert failed to insert PID %d\n", pp->pid);
	    	recycle_process(pp);
	    }
	}
	/* no else, allocate will complain so we don't have to */
} 

/* This function processes the end event */
static void end_process(struct Sim *sp , ulong riv)
{
	/* use the pid passed in */
	int pid = (int) riv;
	int matches = 0;

	/* check three lists, sum the deletes.  SHould be 1.
	 * move to the completed list.  Pass &pid.
	 */

matches += deleteSome(&sp->blocked, pid_matches, &pid, move_to_completed, TEXT);
matches += deleteSome(&sp->ready, pid_matches, &pid, move_to_completed, TEXT);
matches += deleteSome(&sp->running, pid_matches, &pid, move_to_completed, TEXT);

	if(matches == 1)
	{
	    if(DEBUG)printf("DEBUG: end_process: PID %d success\n", pid);
	}
	else
	{
if(TEXT)printf("ERROR: end_process: %d instances of PID %d found.\n", matches, pid);
	}
	
	return;
} 

/* This function processes the time check event */
static void time_check(struct Sim *sp , ulong riv)
{
	/* two passes on running list: iterate to decrement, then delete to
	 * move to ready list */
	iterate(sp->running, dec_ticks);
	deleteSome(&sp->running, zero_ticks, NULL, move_to_ready, TEXT);

	return;
} 

/* This function processes the IO call event */
static void begin_IO(struct Sim *sp , ulong riv)
{
	/* use the pid passed in */
	int pid = (int) riv;
	int matches = 0;

	/* check run list with deletes.  SHould be 1.
	 * move to the blocked list.  Pass &pid.
	 */

matches += deleteSome(&sp->running, pid_matches, &pid, move_to_blocked, TEXT);

	if(matches == 1)
	{
	    if(DEBUG)printf("DEBUG: begin_IO: PID %d success\n", pid);
	}
	else
	{
if(TEXT)printf("ERROR: begin_IO: %d instances of PID %d found.\n", matches, pid);
	}
	
	return;
}


/* This function processes the IO complete event */
static void end_IO(struct Sim *sp , ulong riv)
{
	/* use the pid passed in */
	int pid = (int) riv;
	int matches = 0;

	/* check blockedn list with deletes.  SHould be 1.
	 * move to the ready list.  Pass &pid.
	 */

matches += deleteSome(&sp->blocked, pid_matches, &pid, move_to_ready, TEXT);

	if(matches == 1)
	{
	    if(DEBUG)printf("DEBUG: end_IO: PID %d success\n", pid);
	}
	else
	{
if(TEXT)printf("ERROR: end_IO: %d instances of PID %d found.\n", matches, pid);
	}
	
	return;
} 

/* This function processes the run event */
static void run_process(struct Sim *sp , ulong riv)
{
	/* use the pid passed in */
	int pid = (int) riv;
	int matches = 0;

	/* check ready list with deletes.  SHould be 1.
	 * move to the running list.  Pass &pid.
	 */

matches += deleteSome(&sp->ready, pid_matches, &pid, move_to_running, TEXT);

	if(matches == 1)
	{
	    if(DEBUG)printf("DEBUG: run_process: PID %d success\n", pid);
	}
	else
	{
if(TEXT)printf("ERROR: run_process: %d instances of PID %d found.\n", matches, pid);
	}
	
	return;
} 

/* public code below here */

/* This function checks if an event is valid */
int valid_event(int event)
{
	int rval = 0;
char *names[] = {"START", "END", "TIME", "IO_CALL", "IO_COMPLETE", "RUN"};
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
if(DEBUG)printf("DEBUG: valid_event: %d (%s) is good\n", event, names[event]);
		break;
	    /* default means I don't know this event */
	    default:
if(TEXT)printf("ERROR: valid_event: %d is an invalid event. TERMINATING.\n",event);
	    	break;
	}
	return rval;

}

/* This function determines which event to process */
void handle_event(struct Sim *sp, int event, ulong riv)
{
	/* my jump table - better match the event values */
	void (*jump[])(struct Sim *sp, ulong riv) = {
		start_process, 
		end_process,
		time_check,
		begin_IO,
		end_IO,
		run_process };

	/* I'm dead if that subscript is out of bounds*/
	/* who you gonna call?...*/
	jump[event](sp, riv);
	
}
	    	

	    
