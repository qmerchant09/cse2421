
/* libos.h  is Copyright 2021 by Neil Kirby.  Not for distribution */

/* time related */
int millisleep(unsigned int milliseconds);
double now();

/* graphics related */

void os_clear(int steps);
int os_initialize(int core_count);
int os_process(int event, unsigned char priority, int pid, unsigned short ticks, unsigned char state);
void os_refresh();
void os_status(const char *statstr);
void os_teardown();
