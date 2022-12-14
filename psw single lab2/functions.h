/* Quantez Merchant */
/* This file contains the headers to all the functions used in lab2 */

#include <stdio.h>

unsigned long processStart (unsigned long psw);

unsigned char unpackPriority (unsigned long psw);

unsigned char unpackState (unsigned long psw);

int unpackPid (unsigned long psw);

unsigned short unpackTicks (unsigned long psw);

unsigned long pack (unsigned char pri, int pid, unsigned short ticks, unsigned char state);

int generateHeader ();

int generateRow (int step, int event, unsigned long psw, unsigned char pri, int pid, unsigned short ticks, unsigned char state);

unsigned long processEvent (int event, unsigned long parameter, double start);

int checkEventValidity (int event);

unsigned long timeCheck (unsigned long psw);

unsigned long ioCall (int pid, unsigned long psw);

unsigned long ioComplete (int pid, unsigned long psw);

unsigned long run (int pid, unsigned long psw);

int terminate (double now);

int graphicsMode (int event, unsigned long currentPsw, unsigned long psw, int step, double start);

int textMode (int event, unsigned long currentPsw, unsigned long psw, int step, double start);
