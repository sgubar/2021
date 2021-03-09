#include <stdio.h>
#include "point.h"
#include "line.h"
#include "triangle.h"

int main(int argc, const char * argv[])
{										// (1.2) (3.4) (6.5) 
										// (1.1) (5.1) (8.1)
		
//		Triangle* ABC = createTreangleByPoint(createPoint(1, 1), createPoint(5, 1), createPoint(8, 1)); //ERROR, non-existent triangle
		Triangle* ABC = createTreangleByPoint(createPoint(1, 2), createPoint(3, 4), createPoint(6, 5)); //working

		printTriangle(ABC);
		deleteTriangle(ABC);

	return 0;
}
