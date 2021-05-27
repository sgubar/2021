#include <stdio.h>
#include <stdlib.h>
#include "points.h"
#include "triangle.h"
#include "ArrayOfTriangle.h"

int main()
{
    printf("Hello world!\n");
  Point *p1=createPoint(0,0);
  Point *p2=createPoint(8,0);
  Point *p3=createPoint(0,6);
  Point *p4=createPoint(0,4);
  Point *p5=createPoint(3,0);
  Point *p6=createPoint(0,12);
  Point *p7=createPoint(9,0);


  Triangle *tr1=createTriangleByPoints(p1,p2,p3);
  Triangle *tr2=createTriangleByPoints(p1,p4,p5);
  Triangle *tr3=createTriangleByPoints(p1,p6,p7);

  ArrayTriangle* array = createArrayTriangle(3);

  printArrayTriangle(array);

  addNewTriangleToArray(array,tr1);
  addNewTriangleToArray(array,tr2);
  addNewTriangleToArray(array,tr3);

  printArrayTriangle(array);

  Point *p8=createPoint(0,16);
  Point *p9=createPoint(12,0);
  Triangle *tr4=createTriangleByPoints(p1,p8,p9);

  TriangleAtIndex(array,tr4,2);

  printArrayTriangle(array);

  deletePoint(p1);
  deletePoint(p2);
  deletePoint(p3);
  deletePoint(p4);
  deletePoint(p5);
  deletePoint(p6);
  deletePoint(p7);
  deletePoint(p8);
  deletePoint(p9);

  deleteTriangle(tr1);
  deleteTriangle(tr2);
  deleteTriangle(tr3);
  deleteTriangle(tr4);

  deleteArrayTriangle(array);
    return 0;
}
