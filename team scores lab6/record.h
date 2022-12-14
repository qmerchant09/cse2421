
struct Record {
    char name[15];
    short scores[2][6];
    int win, loss, tie;
};

struct Record *mshim(struct Record *rp, int count);
int sshim(struct Record *rp);
int oshim(struct Record *rp);

/* leave these commented out - call the shims instead
 * struct Record *bestMargin(struct Record *rp, int count);
 * int stats(struct Record *rp);
 * int oneTeam(struct Record *rp);
 */

