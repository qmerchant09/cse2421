

/* COpyright 2021 Neil Kirby */

void clear_completed(struct Sim *sp);
void handle_event(struct Sim *sp, int event, ulong riv);
void move_to(void *aoh, struct Proc *pp, char *list_name);
void move_to_completed(void *data);
void purge(struct Sim *sp);
int valid_event(int event);
