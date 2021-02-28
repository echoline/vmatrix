#include "vmatrix.h"
#include "vmatrixio.h"
#include "vmatrixop.h"
#include <stddef.h>

int main() {
	vmatrix *a, *b, *c;

	a = vmatrixread(0);
	b = vmatrixread(0);

	if (a == NULL || b == NULL)
		return -1;

	c = vmatrixmul(a, b);

	if (c == NULL)
		return -1;

	vmatrixwrite(1, c);

	return 0;
}

