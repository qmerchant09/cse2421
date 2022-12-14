/* Quantez Merchant */

#include <stdio.h>

int main () {
int step = 0;
int pri = 0;
int pid = 0;
int ticks = 0;
int state = 0;
int event = 1;

printf ("STEP ");
printf ("EVENT ");
printf ("__PSW__            ");
printf ("PRI     ");
printf ("PID ");
printf ("TICKS ");
printf ("STATE\n");
printf ("%4d", step);
printf ("%6d", event);
printf (" 0x0000000000000000");
printf ("%4d", pri);
printf ("%8d", pid);
printf ("%6d", ticks);
printf ("%6d", state);
printf ("\n");


step = 1234;
pri = 139;
pid = 4194304;
ticks = 12345;
state = 255;

printf ("%4d", step);
printf ("%6d", event);
printf (" 0x8B004000003039FF");
printf ("%4d", pri);
printf ("%8d", pid);
printf ("%6d", ticks);
printf ("%6d", state);
printf ("\n");
return 0;
}
