#include <stdio.h>
#include <stdlib.h>
#include "points.h"
#include "triangle.h"

int main()
{
    printf("Hello world!\n");
  Point *p1=createPoint(0,0);
  Point *p2=createPoint(8,0);
  Point *p3=createPoint(0,6);
  Triangle *tr=createTriangleByPoints(p1,p2,p3);
  printTriangle(tr);
  printf("sguare of triangle %f\n",SquareOfTriangle(tr));
  printf("perimetr of triangle %f\n",PerimetrOfTriangle(tr));
  deletePoint(p1);
  deletePoint(p1);
  deletePoint(p1);
  deleteTriangle(tr);
    return 0;
}
