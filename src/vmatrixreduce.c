#include "vmatrix.h"
#include "vmatrixio.h"
#include "vmatrixop.h"
#include <stddef.h>

int main() {
	vmatrix *a, *b;

	a = vmatrixread(0);

	if (a == NULL)
		return -1;

	b = vmatrixreduce(a);

	if (b == NULL)
		return -1;

	vmatrixwrite(1, b);
}

