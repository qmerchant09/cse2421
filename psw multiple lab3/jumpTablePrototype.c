/* Quantez Merchant */

#include <stdio.h>
#include <stdlib.h>

int p1 () {return 1+1;}

int p2 () {return 2+2;}

int p3 () {return 3+3;}

int p4 () {return 4+4;}

int p5 () {return 5+5;}

int main () {
	int ret;
	int num1;
	int (*returnNum[5]) () = {p1,p2,p3,p4,p5};
	printf ("Type a number: ");
	scanf ("%d", &num1);
	if ((num1 > 0) && (num1 <= 5)) {
		ret = returnNum[--num1]();
	printf("The number is: %d\n", ret);
	}else {
		printf ("Try again\n");
	}
	return 0;
}
