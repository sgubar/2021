#include <stdio.h>
#include "point.h"
#include "triangle.h"
#include <stdlib.h>
#include <math.h>
#include "line.h"

Triangle *createTriangleByPoints(Point *p1, Point *p2,Point *p3){
if (NULL == p1 || NULL == p2 || NULL == p3) {
		return NULL;
	}

	Triangle *tr = (Triangle *)malloc(sizeof(Triangle));
	if (NULL != tr) {
		tr->A = copyPoint(p1);
		tr->B = copyPoint(p2);
		tr->C = copyPoint(p3);



	}

	return tr;

}

float TriangleIsRectangular(Line *l1,Line *l2,Line *l3){
 float a = lenghtLine(l1);
 float b = lenghtLine(l2);
 float c = lenghtLine(l3);
 float gipo=0;
 float kat1=0;
 float kat2=0;

 if (a>b) {gipo = a;}
    else { gipo =b;}
    if (gipo<c) {gipo=c;}
//printf("ddfsdfzs %f",gipo);

 if (a!=gipo)
    {
        kat1=a;
        if (b!=gipo)
        {
          kat2=b;
        } else{kat2=c;}
    }
  else {kat1=b;
        kat2=c;}
//printf("tttttt %f,%f,%f", gipo,kat1,kat2);

 if (gipo*gipo==(kat1*kat1)+(kat2*kat2))
 {
     printf ("triangle is rectangular and for this task is correct\n");
     printf("square of triangle is %f\n",(kat1*kat2)/2);
     printf("perimeter of triangle is %f\n",gipo+kat1+kat2);
 }else
 {
     printf("this triangle is not rectangular, is not correct for this task,but this is triangle\n");
     return 0;
 }



}


void deleteTriangle(Triangle *tr)
{
    if (NULL != tr) {
		deletePoint(tr->A);
		deletePoint(tr->B);
		deletePoint(tr->C);

		free(tr);
	}
}

void printTriangle(Triangle *tr){
     if (NULL != tr) {
		printPoint(tr->A);
		printf("-");
		printPoint(tr->B);
		printf("-");
		printPoint(tr->C);
		printf("\n");
	}
}
