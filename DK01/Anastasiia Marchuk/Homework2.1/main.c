#include <stdio.h>
#include <math.h>
#include "point.h"
#include "line.h"

int main(int argc, const char * argv[]) {


	Point *p1 = createPoint(4, 3);
  Point *p2 = createPoint(10, 9);
  Point *p3 = createPoint(2, 11);

	printPoint(p1);
	printf("\n");
  
  printPoint(p2);
	printf("\n");
  
  printPoint(p3);
	printf("\n");

  Line1 *l1 = createLine1ByPoints(p1, p2);
  Line2 *l2 = createLine2ByPoints(p2, p3);
  Line3 *l3 = createLine3ByPoints(p3, p1);
  
	printf("len_1: %f\n", lenghtLine1(l1));
  printf("len_2: %f\n", lenghtLine2(l2));
  printf("len_3: %d\n", lenghtLine3(l3));


  deletePoint(p1);
  deletePoint(p2);
  deletePoint(p3);
  deleteLine1(l1);
  deleteLine2(l2);
  deleteLine3(l3);

  return 0;
}
