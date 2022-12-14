/* Quantez Merchant */


int priority_order (void *data1, void *data2);

void move_to_running (void *data);
void move_to_completed (void *data);
void move_to_ready (void *data);
void move_to_blocked (void *data);
void dec_ticks (void *data);
void recycle_process (void *data);

int always_true (void *data, void *helper);
int zero_ticks (void *data, void *helper);
int pid_matches (void *data, void *helper);
