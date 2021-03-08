#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "triangle.h"
#include "line.h"

int main()
{
    Point *p1 = createPoint(0, 0);
    Point *p2 = createPoint(4, 0);
    Point *p3 = createPoint(0, 3);

    Line *l1=createLineByPoints(p1,p2);
    Line *l2=createLineByPoints(p2,p3);
    Line *l3=createLineByPoints(p3,p1);

   // printPoint(p1);

    //printf("%f\n",lenghtLine(l1));
   // printf("%f\n",lenghtLine(l2));
   // printf("%f\n",lenghtLine(l3));

    Triangle *tr = createTriangleByPoints(p1, p2,p3);
    TriangleIsRectangular(l1,l2,l3);
	printTriangle(tr);


    deletePoint(p1);
    deletePoint(p2);
    deletePoint(p3);

    deleteLine(l1);
    deleteLine(l2);
    deleteLine(l3);

    deleteTriangle(tr);

    //printf("Hello world!\n");
    return 0;
}
