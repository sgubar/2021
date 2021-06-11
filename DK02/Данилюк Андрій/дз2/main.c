#include <stdio.h>
#include "point.h"
#include "line.h"
#include "triangle.h"

int main(int argc, const char * argv[])
{
		Triangle* ABC = createTreangleByPoint(createPoint(1, 2), createPoint(3, 4), createPoint(6, 5));

		printTriangle(ABC);
		deleteTriangle(ABC);

	return 0;
}
