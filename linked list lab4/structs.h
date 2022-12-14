
struct Sim
{
	int step;
	/* my 3 list head pointers */
	void *completed, *blocked, *ready, *running;
	FILE *fp;

};

struct Proc
{
	int runtime, pid;
	unsigned char state, priority;
	unsigned short ticks;
	struct Sim *system;
};

