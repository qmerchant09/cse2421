/* Quantez Merchant */
/* This file contains functions that handle the events */

#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "state.h"
#include "functions.h"
#include "debug.h"
#include "libos.h"
#define DEFAULTTICKS 4

/* This function applies the properties of the process start event to the psw */
unsigned long processStart (unsigned long psw) {
	unsigned char pri = unpackPriority(psw);
	int pid = unpackPid(psw);
	unsigned long newPsw;

	if (DEBUG) printf ("DEBUG: processStart: creating PID %d priority %d\n",pid,pri);
	newPsw = pack(pri,pid,DEFAULTTICKS,READY);

	return newPsw;

}

/* This function applies the properties of the process end event to the psw */
unsigned long processEnd (int pid, unsigned long psw) {
	unsigned long newPsw = psw;
	
	if(unpackPid(psw) != pid) {
		if (TEXT) printf ("ERROR: procsessEnd: could not find PID %X\n", pid);
	}else {
		if (DEBUG) printf ("DEBUG: processEnd: PID %d\n",pid);
		newPsw = pack (unpackPriority(psw),pid,0,COMPLETE);
	}

	return newPsw;
}

/* This function applies the properties of the time check event to the psw */
unsigned long timeCheck (unsigned long psw) {
	unsigned char state = unpackState(psw), pri = unpackPriority(psw);
	unsigned short ticks = unpackTicks(psw);
	int pid = unpackPid(psw);

	if (state != RUNNING) {
		if (TEXT) printf ("ERROR: timeCheck IGNORED, PID %X is not running.\n",pid);
	}else if (unpackTicks(psw) > 1) {
		ticks--;
		if (DEBUG) printf ("DEBUG: timeCheck: PID %d has ticks = %d\n",pid,ticks);
	}else {
		ticks--;
		state = READY;
		if (DEBUG) printf ("DEBUG: timeCheck: suspending PID %d\n",pid);
	}

	return psw = pack(pri,pid,ticks,state);
}

/* This function applies the properties of the io call event to the psw */
unsigned long ioCall (int pid, unsigned long psw) {
	unsigned long newPsw = psw;

	if (unpackPid(psw) != pid) {
		if(TEXT) printf ("ERROR: ioCall: could not find PID %X\n",pid);
	}else {
		if (DEBUG) printf ("DEBUG: ioCall: blocking PID %d\n",pid);
		newPsw = pack(unpackPriority(psw),pid,unpackTicks(psw),BLOCKED);	
	}

	return newPsw;
}

/* This function applies the properties of the io complete event to the psw */
unsigned long ioComplete (int pid, unsigned long psw) {
	unsigned long newPsw = psw;

	if (unpackPid(psw) != pid){
		if (TEXT) printf ("ERROR: ioComplete: could not find PID %X\n",pid);
	}else {
		if (DEBUG) printf ("DEBUG: ioComplete: enabling PID %d\n",pid);
		newPsw = pack(unpackPriority(psw),pid,unpackTicks(psw),READY);
	}

	return newPsw;
}

/* This function applies the properties of the run event to the psw */
unsigned long run (int pid, unsigned long psw) {
	unsigned long newPsw = psw;

	if (unpackPid(psw) != pid) {
		if (TEXT) printf ("ERROR: run: could not find PID %X\n",pid);
	}else if (unpackState(psw) != READY) {
		if (TEXT) printf ("ERROR: run: PID %X is not READY\n",pid);
	}else {
		if (DEBUG) printf ("DEBUG: run: RUNNING PID %d\n",pid);
		newPsw = pack(unpackPriority(psw),pid,DEFAULTTICKS,RUNNING);
	}

	return newPsw;
}

/* This function takes the event number and sends it to the appropriate event */
unsigned long processEvent (int event, unsigned long parameter, double start) {
	unsigned long psw = 0;
	int pid = 0;

	switch (event){
	case S:
		if (scanf ("%lX", &parameter) != 1) terminate(start);
		psw = processStart(parameter);
		break;
	case E: 
		if (scanf ("%X", &pid) != 1) terminate(start);
		psw = processEnd(pid,parameter);
		break;
	case T: 
		if (scanf ("%X", &pid) != 1) terminate(start);
		psw = timeCheck(parameter);
		break;
	case A:
		if (scanf ("%X", &pid) != 1) terminate(start);
		psw = ioCall(pid,parameter);
		break;
	case O: 
		if (scanf ("%X", &pid) != 1) terminate(start);
		psw = ioComplete(pid,parameter);
		break;
	case R: 
		if (scanf ("%X", &pid) != 1) terminate(start);
		psw = run(pid,parameter);
		break;
	default:		
		break;
	}

	return psw;
}

/* This function determines whether an event is valid or not */
int checkEventValidity (int event) {
	if (event < 0 || event > R) {
		if (TEXT) printf ("ERROR: checkEventValidity: %d is an invalid event. TERMINATING.\n", event);
		return 1;
	}else if (DEBUG) {
		printf ("DEBUG: checkEventValidity: %d is valid\n",event);
	}
	return 0;

}

/* This function terminates the program */
int terminate (double start) {
	double end;
	int returnNum;
	if (GRAPHICS){
		os_teardown();
	}
	printf ("Input terminated: scanf returned %d\n", scanf("%X",&returnNum));
	end = now();
	printf ("Total runtime is %.9f seconds.\n", end-start);
	exit(0);
}









