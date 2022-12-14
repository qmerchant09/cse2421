/* Quantez Merchant */

/* Changes to Professor Kirbys code */
/* Changed the code or headers for all functions, added one job comments */
/* Copyritght 2021 Neil Kirby.  Not for disclosure */
#include <stdio.h>

#include "utypes.h"

#include "debug.h"

#include "libos.h"

#include "psw.h"

#include "structure.h"

#include "linkedlist.h"

/* This function prints the text mode header */
static void print_header(int step)
{
	printf("Step %3d:\n%s%14s%15s%8s%6s%6s\n", 
		step, "List", "__PSW__", "PRI", "PID", "TICKS", "STATE");

}

/* This function determines if a header should be printed */
void initial_output(int step)
{
	if(TEXT) print_header(step);
}

/* This function clears the graphics area */
void begin_output(int step)
{
	if(GRAPHICS)os_clear(step);
}

/* This function displays the graphics */
void finalize_output()
{
	if(GRAPHICS)
	{
	    os_refresh();
	    millisleep(1000);
	}
}
/* This function prints the output data in text mode  */
void print_text (void *data) {
        struct Process *p = data;
	        printf("%13s%lX %3d %7d %5d %5d\n","0x",pack_psw(p->pri,p->pid,p->ticks,p->state), p->pri, p->pid, p->ticks,p->state);
}

/* This function draws the output data in graphics mode */
void draw_graphics (void *data) {
	struct Process *p = data;
	os_process(0,p->pri,p->pid,p->ticks,p->state);
}

/* This function calls the draw_graphics action function */
static int draw_process(int event, struct Simulation *s)
{ 
	iterate (s->complete, draw_graphics);
	iterate (s->blocked, draw_graphics);
	iterate (s->ready, draw_graphics);
	iterate (s->running, draw_graphics);
	return 1;
}

/* This function calls the print_text action function */
static int print_process(struct Simulation *s)
{
	int rval = 0;
	int rival;

	printf("%s\n", "COMPLETE");
	iterate (s->complete, print_text);
	printf("%s\n", "BLOCKED");
	iterate (s->blocked, print_text);
	printf("%s\n", "READY");
	iterate (s->ready, print_text);
	printf("%s\n", "RUNNING");
	iterate (s->running, print_text);
	printf ("\n");
	rival = 1;
	
	return rval;
}

/* This function determines which print function to call */
int master_output(struct Simulation *s)
{
	int rval = 0;
	if(TEXT)rval = print_process(s);
	if(GRAPHICS) rval = draw_process(0, s);

	return rval;
}

