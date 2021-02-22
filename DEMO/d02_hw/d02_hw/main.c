//
//  main.c
//  d02_hw
//
//  Created by Slava Gubar on 17.02.2021.
//

#include <stdio.h>
#include "line.h"
#include "polyline.h"

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

	printf("Polyline test ...\n");
	PolyLine *line = createPolyLine();

	addPointToPolyLine(line, p);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 7, 8);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 97, 78);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 87, 58);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 77, 88);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 37, 48);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	// insert code here...
	printf("Hello, World!\n");
	deletePoint(p);
	deletePoint(copy);
	deleteLine(l);
	deletePolyLine(line);
	return 0;
}
