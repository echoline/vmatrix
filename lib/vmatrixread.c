#include "vmatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

vmatrix*
vmatrixread(int fd)
{
	char *buf;
	int l, o, p, u, v, m, n, r;
	double d;
	vmatrix *ret;

	l = 8192;
	o = 0;
	p = 0;
	m = 0;
	n = 0;
	u = 0;
	v = 0;
	ret = NULL;
	buf = malloc(l);

	while((r = read(fd, &buf[o], l - o - 1)) > 0) {
		l += r;
		o += r;

		buf[o] = '\0';

		buf = realloc(buf, l);

		do {
			if (ret == NULL) {
				while (isspace(buf[p]))
					p++;

				if (buf[p] == '\0')
					continue;

				if (m == 0) {
					if (sscanf(&buf[p], "%d", &m) != 1 || m == 0)
						goto err;
				} else if (n == 0) {
					if (sscanf(&buf[p], "%d", &n) != 1 || n == 0)
						goto err;

					ret = vmatrixalloc(m, n);
				}

				while (isdigit(buf[p]))
					p++;
			} else {
				while (isspace(buf[p]))
					p++;

				if (buf[p] == '\0')
					break;

				if (!isdigit(buf[p]) && buf[p] != '.' && buf[p] != '-')
					goto err;

				if (sscanf(&buf[p], "%lf", &d) != 1)
					goto err;

				ret->d[u][v] = d;

				if (v < n)
					v++;

				if (v >= n) {
					v = 0;
					u++;

					if (u >= m)
						goto end;
				}

				while (isdigit(buf[p]) || buf[p] == '.' || buf[p] == '-')
					p++;
			}
		} while(buf[p] != '\0');
	}

end:
	free(buf);
	buf = NULL;

	if (u >= m)
		return ret;

	if (r < 0)
		perror("read");

err:
	if (buf != NULL)
		free(buf);

	if (ret != NULL)
		vmatrixfree(ret);

	return NULL;
}

