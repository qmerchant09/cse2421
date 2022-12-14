/* Quantez Merchant */

/* This program tests the unpacking process of the psw */

#include <stdio.h>

int main () {
unsigned long psw = 0x1234567890ABCDEF;
unsigned char pri = 0x00, state = 0x00;
int pid = 0x00000000;
unsigned short ticks = 0x0000;
state =  state |(unsigned char) psw;
psw = psw >> 8;
ticks = ticks |(unsigned short) psw;
psw = psw >> 16;
pid = pid | (int) psw;
psw = psw >> 32;
pri = pri |(unsigned char) psw;
psw = psw >> 8;
printf ("%016lX\n",psw);
printf ("%X\n",state);
printf ("%X\n", ticks);
printf ("%X\n", pid);
printf ("%X\n", pri);

printf ("\n");
return 0;

}
