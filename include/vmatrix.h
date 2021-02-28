typedef struct {
	int m;
	int n;
	double **d;
} vmatrix;

vmatrix* vmatrixalloc(int, int);
void vmatrixfree(vmatrix*);
vmatrix* vmatrixcopy(vmatrix*);

