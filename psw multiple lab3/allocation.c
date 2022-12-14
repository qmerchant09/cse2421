/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "linkedlist.h"
#include "callbacks.h"
#include "debug.h"

/* This function allocates a process */
struct Process* allocate_process (struct Process *p) {
	static int count = 0;
	p = malloc(sizeof(struct Process));
	if (p != NULL) {
		count++;
		printf ("DIAGNOSTIC: allocate_process. %d allocated so far.\n", count);
	}else {
		printf ("ERROR: allocate_process: malloc failed");
	}
	return p;
}

/* This function frees a process */
void recycle_process (void *data) {
	struct Process *p1 = data;
	static int num = 0;
	printf ("DIAGNOSTIC: recycle_process on PID %d which ran %d. %d freed.\n", p1->pid, p1->runtime, ++num);
	free(p1);
	p1 = NULL;
}

/* This function purges all of the lists */
void purge (struct Simulation *s) {
	int rval;
	rval = deleteSome(&s->complete, always_true, NULL, recycle_process, TEXT);
	if (DEBUG) printf("DEBUG: purge: completed: %d deleted.\n", rval);
	rval = deleteSome(&s->blocked, always_true, NULL, recycle_process, TEXT);
	if (DEBUG) printf("DEBUG: purge: blocked: %d deleted.\n", rval);
	rval = deleteSome(&s->ready, always_true, NULL, recycle_process, TEXT);
	if (DEBUG) printf("DEBUG: purge: ready: %d deleted.\n", rval);
	rval = deleteSome(&s->running, always_true, NULL, recycle_process, TEXT);
	if (DEBUG) printf("DEBUG: purge: running: %d deleted.\n", rval);
}
