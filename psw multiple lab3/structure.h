/* Quantez Merchant */

struct Simulation {
	int step;
	void *complete;
	void *blocked;
	void *ready;
	void *running;
	struct Simulation *next;
};

struct Process {
	int runtime;
	int pid;
	unsigned char pri;
	unsigned char state;
	unsigned short ticks;
	struct Simulation *sp;
};
