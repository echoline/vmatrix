#include "vmatrix.h"
#include <stddef.h>
#include <math.h>

vmatrix*
vmatrixreduce(vmatrix *a)
{
	int h, k, m, n, p, i, j;
	double *row;
	double f;
	vmatrix *b;

	if (a == NULL)
		return NULL;

	b = vmatrixcopy(a);

	m = b->m;
	n = b->n;

	h = 0;
	k = 0;

	while (h < m && k < n) {
		f = 0;
		for (i = h; i < m; i++)
			if (fabs(b->d[i][k]) > fabs(f)) {
				p = i;
				f = b->d[i][k];
			}

		if (f == 0)
			k++;
		else {
			row = b->d[h];
			b->d[h] = b->d[p];
			b->d[p] = row;

			for (i = h+1; i < m; i++) {
				f = b->d[i][k] / b->d[h][k];
				b->d[i][k] = 0;
				for (j = k+1; j < n; j++)
					b->d[i][j] -= b->d[h][j] * f;
			}

			h++;
			k++;
		}
	}

	return b;
}
