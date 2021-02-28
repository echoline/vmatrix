#include "vmatrix.h"
#include <stdlib.h>

void
vmatrixfree(vmatrix *v)
{
	int i;

	for (i = 0; i < v->m; i++)
		free(v->d[i]);

	free(v->d);

	free(v);
}

