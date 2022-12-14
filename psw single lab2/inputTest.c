/* Quantez Merchant */

#include <stdio.h>
#include "functions.h"


int main () {
int event = 0;
unsigned long psw = 0;
while (scanf ("%X", &event) != EOF) {
printf ("%d\n", event);
scanf ("%lX", &psw);
printf ("%lX\n",psw);
}

return 0;
}
