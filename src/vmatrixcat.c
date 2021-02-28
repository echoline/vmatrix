#include "vmatrix.h"
#include "vmatrixio.h"
#include <stddef.h>

int main() {
	vmatrix *v;

	while ((v = vmatrixread(0)) != NULL) {
		vmatrixwrite(1, v);
		vmatrixfree(v);
	}
}

