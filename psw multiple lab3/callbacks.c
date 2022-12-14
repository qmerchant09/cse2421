/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "libos.h"
#include "utypes.h"
#include "structure.h"
#include "psw.h"
#include "states.h"
#include "debug.h"
#include "allocation.h"


/* Comparison Functions */

/* This function sorts the list into priority order */
int priority_order (void *data1, void *data2) {
	struct Process *p1 = data1;
	struct Process *p2 = data2;
	if (p1->pri < p2->pri) {
		return 1;
	}
	return 0;
}

/* Action Functions */

/* This function moves a process to the running list */
void move_to_running (void *data) {
	struct Process *p1 = data;
	int rval;
	p1->ticks = DEFAULT_TICKS;
	p1->state = RUNNING;
	rval = insert (&p1->sp->running, p1, priority_order, TEXT);
	if (rval == 0) {
		recycle_process (p1);
	} 
	if (DEBUG) printf("DEBUG: move_to_running for PID %d\n", p1->pid);	
}

/* This function moves a process to the completed list */
void move_to_completed (void *data) {
	struct Process *p1 = data;
	int rval;
	p1->state = COMPLETE;
	rval = insert (&p1->sp->complete, p1, priority_order, TEXT);
	if (rval == 0) {
		recycle_process (p1);
	} 
	if (DEBUG) printf("DEBUG: move_to_completed for PID %d\n", p1->pid);	
}

/* This function moves a process to the ready list */
void move_to_ready (void *data) {
	struct Process *p1 = data;
	int rval;
	p1->state = READY;
	rval = insert (&p1->sp->ready, p1, priority_order, TEXT);
	if (rval == 0) {
		recycle_process (p1);
	} 
	if (DEBUG) printf("DEBUG: move_to_ready for PID %d\n", p1->pid);	
}

/* This function moves a process to the blocked list */
void move_to_blocked (void *data) {
	struct Process *p1 = data;
	int rval;
	p1->state = BLOCKED;
	rval = insert (&p1->sp->blocked, p1, priority_order, TEXT);
	if (rval == 0) {
		recycle_process (p1);
	} 
	if (DEBUG) printf("DEBUG: move_to_blocked for PID %d\n", p1->pid);	
}

/* This function decrements the ticks and increments the runtime */
void dec_ticks (void *data) {
	struct Process *p1 = data;
	p1->ticks--;
	p1->runtime++;
}


/* Critera Functions */

/* This function returns true */
int always_true (void *data, void *helper) {
	return 1;
}

/* This function determines if a process has zero ticks */
int zero_ticks (void *data, void *helper) {
	struct Process *p1 = data;
	if (p1->ticks == 0) {
		return 1;
	}
	return 0;
}

/* This function determines if the read in value matches the pid of a process on the list */
int pid_matches (void *data, void *helper) {
	struct Process *p1 = data;
	int pid = *(int*)helper;
	if (pid == p1->pid) {
		return 1;
	}
	return 0;
}

