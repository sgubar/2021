#include <stdio.h>
#include "arrays.h"

int main(void)
{
	PPoint p1, p2;
	PLine l;
	PCircle c;
	printf("Enter the number of circles:\n ");
	PArray array = makeArrayCircles(getNum());
	printf("Put the circles into the array\n The first point is for the center\n");
	setCirclesAtArray(array);
	printf("Add another Circle into array(realocate)\n");
	setCircleAtTheEnd(array, c = makeCircle(l = makeLine(p1 = getPoint(), p2 = getPoint())));
	printArrayCircles(array);
	deleteArrayCircles(array);
}
