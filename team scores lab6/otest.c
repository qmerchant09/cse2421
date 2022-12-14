

/* otest CSE 2421 AU 2021 */
#include <stdio.h>
#include "record.h"


int otest(struct Record *rp)
{
	int points;

	printf("otest: %s\n", rp->name);
	printf("Before: record shows %d win, %d lost, %d tie\n", 
	    rp->win, rp->loss, rp->tie );
    	points = oshim(rp);
	printf("\nAfter: record shows %d win, %d lost, %d tie\n", 
	    rp->win, rp->loss, rp->tie );
	printf("Total points was %d\n", points);
    	return points;
}

int main()
{
	struct Record season =
	{ "Iowa", 
	    {
		{20, 20, 49, 35, 41, 26 },
		{24, 20,  7,  7, 21, 20 },
	    },
	    0, 0, 0
	};

	otest(&season);

	return 0;

}


