#include "vmatrix.h"
#include <stddef.h>

vmatrix*
vmatrixmul(vmatrix *a, vmatrix *b)
{
	vmatrix *ret;
	int i, j, k;

	if (a == NULL || b == NULL)
		return NULL;

	if (a->n != b->m)
		return NULL;

	ret = vmatrixalloc(a->m, b->n);

	for (i = 0; i < a->m; i++)
		for (j = 0; j < b->n; j++)
			for (k = 0; k < a->n; k++)
				ret->d[i][j] += a->d[i][k] * b->d[k][j];

	return ret;
}
