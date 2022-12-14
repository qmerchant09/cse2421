
/* Copyright Neil Kirby 2021.  Not for distribution */
#include "utypes.h"
#include "bits.h" /* must include utpyes prior to this */

/* This function gets the priority from the psw */
uchar ps_priority(ulong psw)
{
	return (uchar)   (psw >> PRI_SHIFT);
}

/* This function gets the pid from the psw */
int ps_pid (ulong psw)
{
	return (int) (psw >> PID_SHIFT) ;
}

/* This function gets the ticks from the psw */
ushort ps_ticks(ulong psw)
{
	return (ushort) (psw >> TICKS_SHIFT) ;
}

/* This function gets the state from the psw */
uchar ps_state(ulong psw)
{
	return (uchar) (psw >> STATE_SHIFT) ;
}

/* This function creates the psw from the priority, pid, ticks, and state */
ulong pack_psw( uchar priority, int pid, ushort ticks, uchar state)
{
	return (
		( (ulong) priority << PRI_SHIFT) |
		( (ulong) pid << PID_SHIFT) |
		( (ulong) ticks << TICKS_SHIFT) |
		( (ulong) state << STATE_SHIFT)
		);

}
