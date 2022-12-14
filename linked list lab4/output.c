
/* Copyritght 2021 Neil Kirby.  Not for disclosure */
#include <stdio.h>

#include "utypes.h"
#include "structs.h"

#include "debug.h"

#include "libos.h"
#include "linkedlist.h"

#include "psw.h"

/* This function prints the text mode header */
static void print_header(int step)
{
	printf("Step %3d:\n", step);
	printf("%-10s __%-16s %3s %7s %5s %5s\n", "List",
		"PSW__", "PRI", "PID", "TICKS", "STATE");

}

/* This function draws a process */
void draw_process(void *data)
{
	struct Proc *pp = data;

	os_process( 0, pp->priority, pp->pid, pp->ticks, pp->state);

}

/* This function prints a process */
void print_process(void *data)
{
	struct Proc *pp = data;

	/* ("STEP EVENT PSW PRI PID TICKS STATE\n") */
	printf("%10s 0x%016lX %3u %7d %5hu %5u\n", "",
	    pack_psw( pp->priority, pp->pid, pp->ticks, pp->state),
	    pp->priority, pp->pid, pp->ticks, pp->state);

}

/* This function prints the data in all the lists */
void printed_output(struct Sim *sp)
{
	print_header(sp->step);
	printf("COMPLETED\n");
	iterate(sp->completed, print_process);
	printf("BLOCKED\n");
	iterate(sp->blocked, print_process);
	printf("READY\n");
	iterate(sp->ready, print_process);
	printf("RUNNING\n");
	iterate(sp->running, print_process);
	printf("\n");
}

/* This function draws the data on the lists */ 
void drawn_output(struct Sim *sp)
{
	os_clear(sp->step);
	
	iterate(sp->completed, draw_process);
	iterate(sp->blocked, draw_process);
	iterate(sp->ready, draw_process);
	iterate(sp->running, draw_process);

	os_refresh();
	millisleep(1000);
}

/* This function determines whether to print or draw */
void master_output(struct Sim *sp)
{
	if(TEXT)printed_output(sp);
	if(GRAPHICS) drawn_output(sp);

}

