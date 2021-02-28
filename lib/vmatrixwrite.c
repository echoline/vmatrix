#include "vmatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
vmatrixwrite(int fd, vmatrix *v)
{
	int m, n;
	char *buf;
	int l;
	int o;
	int r;

	l = 8192;
	o = 0;
	buf = malloc(l);

	r = sprintf(buf, "%d ", v->m);
	l += r;
	o += r;
	buf = realloc(buf, l);
	r = sprintf(&buf[o], "%d\n", v->n);
	l += r;
	o += r;
	buf = realloc(buf, l);

	for (m = 0; m < v->m; m++) {
		for (n = 0; n < v->n; n++) {
			r = sprintf(&buf[o], "%lf ", v->d[m][n]);
			l += r;
			o += r;
			buf = realloc(buf, l);
		}
		buf[o-1] = '\n';
	}

	write(fd, buf, o);
	free(buf);
}

