#include <stdio.h>

#include"areytriangle.h"
int main() {
	AreyTria* One = createAreyTria();

	PutTriangleInArey(One, createTriangleByPoints(createPoint(0, 0), createPoint(0, 1), createPoint(0, 0)));
	// wrond tria just will skip
	PutTriangleInArey(One, createTriangleByPoints(createPoint(1, 0), createPoint(0, 0), createPoint(0, 1)));
	PutTriangleInArey(One, createTriangleByPoints(createPoint(2, 0), createPoint(0, 0), createPoint(2, 1)));
	PutTriangleInArey(One, copyTria(One->arrey[0]));
	printAreyTria(One);
	deleteAreyTria(One);
	One = NULL;
	printAreyTria(One);
	
	return 0;
}
