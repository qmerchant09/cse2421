/* Quantez Merchant */
/* This file contains functions to process the program in either text or graphics mode */

#include <stdio.h>
#include "functions.h"
#include "libos.h"
#define THOUSAND 1000

/* This function processes the program with graphics */
int graphicsMode (int event, unsigned long currentPsw, unsigned long psw, int step, double start) {
	while (scanf ("%X", &event) != EOF) {
		if (checkEventValidity (event)) terminate(start);
		currentPsw = processEvent (event,psw,start);
		psw = currentPsw;
		os_clear(step++);
		os_process(event, unpackPriority(currentPsw), unpackPid(currentPsw), unpackTicks(currentPsw), unpackState(currentPsw));
		os_refresh();
		millisleep(THOUSAND);
	}
	os_teardown();

	return 0;
}

/* This function processes the program without graphics */
int textMode (int event, unsigned long currentPsw, unsigned long psw, int step, double start) {
	generateHeader();
	while (scanf ("%X", &event) != EOF) {
		if (checkEventValidity(event)) terminate(start);
		currentPsw = processEvent(event,psw,start);
		psw = currentPsw;
		generateRow(step++, event, currentPsw, unpackPriority(currentPsw), unpackPid(currentPsw), unpackTicks(currentPsw), unpackState(currentPsw));
	}

	return 0;
}

