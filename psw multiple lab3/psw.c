
/* Copyright Neil Kirby 2021.  Not for distribution */
#include "utypes.h"
#include "bits.h" /* must include utpyes prior to this */

uchar ps_priority(ulong psw)
{
	return (uchar)   (psw >> PRI_SHIFT);
}

int ps_pid (ulong psw)
{
	return (int) (psw >> PID_SHIFT) ;
}

ushort ps_ticks(ulong psw)
{
	return (ushort) (psw >> TICKS_SHIFT) ;
}

uchar ps_state(ulong psw)
{
	return (uchar) (psw >> STATE_SHIFT) ;
}

ulong pack_psw( uchar priority, int pid, ushort ticks, uchar state)
{
	return (
		( (ulong) priority << PRI_SHIFT) |
		( (ulong) pid << PID_SHIFT) |
		( (ulong) ticks << TICKS_SHIFT) |
		( (ulong) state << STATE_SHIFT)
		);

}
