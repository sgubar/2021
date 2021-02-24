#include <stdio.h>
#include "line.h"
#include "point.h"
#include"triangle.h"
int main() {
	PtCord* point1 = createPoint(2, 0);
	PtCord* point2 = createPoint(4, 3);
	PtCord* point3 = createPoint(6, 0);
	Line* Line1_2 = createLineByPoints(point1, point2);
	Line* Line2_3 = createLineByPoints(point2, point3);
	Line* Line1_3 = createLineByPoints(point1, point3);
	Tria* Test = createTriangleByLine(Line1_2, Line1_3, Line2_3);
	return 0;
}
