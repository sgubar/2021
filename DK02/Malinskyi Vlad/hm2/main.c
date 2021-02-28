#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"

int main()
{
    int x,y;
    printf("Enter x");
scanf("%d",&x);
printf("Enter y");
scanf("%d",&y);

Point *p = createPoint(x,y);
    printf("Point A: ");
    printPoint(p);
    printf("\n");

    printf("Point B: ");
    Point *copy = copyPoint(p);
    copy->x = x+2;
    printPoint(copy);
    printf("\n");

    printf("Point C: ");
    Point *copy1 = copyPoint(p);
    copy1->y = y+2;
    printPoint(copy1);
    printf("\n");

    printf("Point D: ");
    Point *copy2 = copyPoint(p);
    copy2->y = y+2;
    copy2->x = x+2;
    printPoint(copy2);
    printf("\n");

    printf("Square\n");
    Line *l = createLineByPoints(p,copy, copy1, copy2);
    printLine(l);
    printf("is equal points: %d\n", isEqualPoints(p, copy, copy1, copy2));
    printf("Len: %f", lenghtLine(l));
    printf("\n");

    deletePoint(p);
	deletePoint(copy);
	deletePoint(copy1);
	deletePoint(copy2);
	deleteLine(l);

}
