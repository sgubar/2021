#include <stdio.h>
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "triangleArray.h"

int main(int argc, const char * argv[])

		Triangle* ABC = createTreangleByPoint(createPoint(1, 2), createPoint(3, 4), createPoint(6, 5)); //working

	TriangleArray* ts = createTriangleArray(2);
	printTriangleArray(ts);

	addTriangleToTriangleArray(ts, ABC);
	printTriangleArray(ts);

	setTriangleAtIndex(ts, ABC, 0);
	printTriangleArray(ts);

	setTriangleAtIndex(ts, ABC, 4);
	printTriangleArray(ts);

	

	deleteTriangle(ABC);
	deleteTriangleArreay(ts);
	return 0;
}
