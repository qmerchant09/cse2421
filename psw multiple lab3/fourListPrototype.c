/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "utypes.h"
#include "psw.h"

struct Node{
	int s;
	void *c;
	void *b;
	void *re;
	void *ru;
	struct Node *next;
};

struct Process {
	int pid;
	unsigned char state;
	unsigned char pri;
	unsigned short ticks;
	struct Node *n;
};

int priority_order (void *data1, void *data2) {
	struct Process *p1 = data1;
	struct Process *p2 = data2;
	if(p1->pri < p2->pri){
	return 1;
	}
	return 0;
}

void print_process (void *data){
	struct Process *p = data;
	printf ("0x%016lX %2X %6X %2X %2X\n", pack_psw(p->pri,p->pid,p->ticks,p->state), p->pri, p->pid, p->ticks, p->state);
}

void start_event (struct Node *s, unsigned long riv) {
	struct Process *p = malloc(sizeof(struct Process));
	int rval;
	p->pid = ps_pid(riv);
	p->pri = ps_priority(riv);
	p->ticks = 4;
	p->state = 2;
	rval = insert(&s->re,p,priority_order,1);
}

int main (){
	struct Node sim;
	unsigned long psw = 0x800012D687123404;
	unsigned long ppsw = 0;
	unsigned long pppsw = 0x810012D688000402;
	sim.s = 1;
	sim.c = NULL;
	sim.b = NULL;
	sim.re = NULL;
	sim.ru = NULL;
	start_event(&sim,psw);
	start_event(&sim,ppsw);
	start_event(&sim,pppsw);
	iterate (sim.re, print_process);
	printf ("\n");
	return 0;
}

