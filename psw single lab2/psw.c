/* Quantez Merchant */
/* This file contains functions that pack and unpack the psw */

#include <stdio.h>
#include "bitPositions.h"
#include "masks.h"

/* This function unpacks the state from the psw */
unsigned char unpackState (unsigned long psw) {
	unsigned char state;
	unsigned long mask = STATEMASK;

	psw = psw & mask;
	state = (unsigned char) psw;

	return state;
}

/* This function unpacks the ticks from the psw */
unsigned short unpackTicks (unsigned long psw) {
	unsigned short ticks;
	unsigned long mask = TICKSMASK;

	psw = psw & mask;
	psw = psw >> STATE;
	ticks = (unsigned short) psw;

	return ticks;
}

/* This function unpacks the pid from the psw */
int unpackPid (unsigned long psw) {
	int pid;
	unsigned long mask = PIDMASK;

	psw = psw & mask;
	psw = psw >> TICKS + STATE;
	pid = (int) psw;

	return pid;
}

/* This function unpacks the priority from the psw */
unsigned char unpackPriority (unsigned long psw) {
	unsigned char pri;
	unsigned long mask = PRIORITYMASK;

	psw = psw & mask;
	psw = psw >> PID + TICKS + STATE;
	pri = (unsigned char) psw;

	return pri;
}

/* This function packs the psw with the priority, the pid, the ticks and the state */
unsigned long pack (unsigned char pri, int pid, unsigned short ticks, unsigned char state) {
	unsigned long psw;

	psw = psw | pri;
	psw = psw << PID;
	psw = psw | (unsigned long) pid;
	psw = psw << TICKS;
	psw = psw | ticks;
	psw = psw << PRIORITY;
	psw = psw | state;

	return psw;
}







