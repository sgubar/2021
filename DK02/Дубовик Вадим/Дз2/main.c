#include <stdio.h>
#include "arrays.h"

int main(void)
{
	PPoint p1, p2;
	PLine l;
	//Point* a = getPoint();
	PCircle c = makeCircle(l = makeLine(p1 = getPoint(), p2 = getPoint()));
	printCircle(c);
	deleteCircle(c);
}
