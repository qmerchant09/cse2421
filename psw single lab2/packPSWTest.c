/* Quantez Merchant */

/* This prototype tests the packing process for the PSW */

#include <stdio.h>
int main (){
unsigned long psw = 0x0000000000000000;
unsigned char pri = 0x12; 
int pid = 0x34567890;
unsigned short ticks = 0xABCD;
unsigned char state = 0xEF;
psw = psw | pri;
psw = psw << 32;
psw = psw |(unsigned long) pid;
psw = psw << 16;
psw = psw | ticks;
psw = psw << 8;
psw = psw | state;
printf ("%lX",psw);
printf ("\n");
return 0;

}
