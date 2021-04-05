#include <stdio.h>

#include "areytriangle.h"

int main() {
	AreyTria* One = createAreyTria(3);
	PtCord* a = createPoint(0, 0);
	PtCord* b = createPoint(0, 1);
	PtCord* c = createPoint(1, 0);
	PtCord* d = createPoint(2, 0);
	PtCord* e = createPoint(2, 1);

	Tria* test_0 = createTriangleByPoints(a, b, a);
	Tria* test_1 = createTriangleByPoints(c, a, b);
	Tria* test_2 = createTriangleByPoints(d, a, e);
	
	IndexTriaInsert(One, 0, test_0);
	// wrond tria just  skiped
	IndexTriaInsert(One, 1, test_1);
	IndexTriaInsert(One, 6, test_2);

	Tria* test_3 = getTriaAtArey(One, 6);
	IndexTriaInsert(One, 2, test_3);


	printAreyTria(One);

	deleteAreyTria(One);

	deletePoint(test_0);
	deletePoint(test_1);
	deletePoint(test_2);

	deletePoint(b);
	deletePoint(c);
	deletePoint(d);
	deletePoint(e);


	return 0;
}