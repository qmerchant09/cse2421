
/* lab 6 CSE 2421 AU 2021 */
#include <stdio.h>
#include "record.h"

struct Record database[] = 
{

	{ "Northwestern", 
	    {
		{43, 21, 21, 27, 17, 20 },
		{ 3, 20, 13, 20,  7, 29 },
	    },
	    0, 0, 0
	}
	,

	{ "Ohio State", 
	    {
		{52, 38, 49, 42, 52, 22 },
		{17, 25, 27, 35, 12, 10 },
	    },
	    0, 0, 0
	}
	,

	{ "Purdue", 
	    {
		{24, 31, 20, 31, 30, 27 },
		{20, 24, 27, 34, 37, 37 },
	    },
	    0, 0, 0
	}

	,

	{ "Iowa", 
	    {
		{20, 20, 49, 35, 41, 26 },
		{24, 20,  7,  7, 21, 20 },
	    },
	    0, 0, 0
	}

};



int main()
{
	struct Record *best;


	best = mshim(database, 4);
	printf("\nLab6: The best margin comes from %s\n", best->name);

	return 0;
}


