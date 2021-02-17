//
//  main.c
//  d02_hw
//
//  Created by Slava Gubar on 17.02.2021.
//

#include <stdio.h>
#include "point.h"
#include "line.h"

int main(int argc, const char * argv[]) {

	Point *p = createPoint(5, 6);

	printPoint(p);
	printf("\n");

	Point *copy = copyPoint(p);
	copy->x = 10;
	printPoint(copy);
	printf("\n");

	printf("is equal points: %d\n", isEqualPoints(p, copy));

	Line *l = createLineByPoints(p, copy);
	printLine(l);

	printf("len: %f\n", lenghtLine(l));

	// insert code here...
	printf("Hello, World!\n");
	deletePoint(p);
	deletePoint(copy);
	deleteLine(l);
	return 0;
}
