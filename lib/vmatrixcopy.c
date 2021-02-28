#include "vmatrix.h"
#include <string.h>

vmatrix*
vmatrixcopy(vmatrix *a)
{
	vmatrix *b;
	int m;

	b = vmatrixalloc(a->m, a->n);

	for (m = 0; m < a->m; m++)
		memcpy(b->d[m], a->d[m], a->n * sizeof(double));

	return b;	
}

