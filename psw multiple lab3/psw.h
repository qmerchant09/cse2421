
/* Copyright 2021 Neil Kirby.  Not for distribution */

ulong pack_psw( uchar priority, int pid, ushort ticks, uchar state);
int ps_pid (ulong psw);
uchar ps_priority(ulong psw);
uchar ps_state(ulong psw);
ushort ps_ticks(ulong psw);
