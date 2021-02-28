#include "vmatrix.h"
#include <stdlib.h>

vmatrix*
vmatrixalloc(int m, int n)
{
	vmatrix *ret;
	int i;

	ret = calloc(1, sizeof(vmatrix));

	ret->m = m;
	ret->n = n;

	ret->d = calloc(m, sizeof(double*));
	for (i = 0; i < m; i++)
		ret->d[i] = calloc(n, sizeof(double));

	return ret;
}

