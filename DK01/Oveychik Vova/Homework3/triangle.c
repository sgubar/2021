#include <stdio.h>
#include "points.h"
#include "triangle.h"
#include <stdlib.h>
#include <math.h>
double lenghtLin(Point *p1,Point *p2) {
	if (NULL == p1 || NULL ==p2) {
		return -1;
	}

	long dX = p1->x - p2->x;
	long dY = p1->y - p2->y;

	return sqrt(dX*dX + dY*dY);
}

int TriangleIsRectangular(Point *p1,Point *p2,Point *p3){
    if (NULL == p1,NULL == p2,NULL == p3) {
		return NULL;
	}

 double a = lenghtLin(p1,p2);
 double b = lenghtLin(p2,p3);
 double c = lenghtLin(p3,p1);
 double  gipo=0;
 double kat1=0;
 double kat2=0;

 if (a>b) {gipo = a;}
    else { gipo =b;}
    if (gipo<c) {gipo=c;}

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

 if (gipo*gipo==(kat1*kat1)+(kat2*kat2))
 {

     return 1;

 }else
 {

     return 0;
 }



}






Triangle *createTriangleByPoints(Point *p1, Point *p2,Point *p3){
if (NULL == p1 || NULL == p2 || NULL == p3) {
		return NULL;
	}


  if (TriangleIsRectangular(p1,p2,p3)==0){

		return NULL;
        printf("triangle is not rectangular");
	}


	Triangle *tr = (Triangle *)malloc(sizeof(Triangle));
	if (NULL != tr) {
		tr->A = copyPoint(p1);
		tr->B = copyPoint(p2);
		tr->C = copyPoint(p3);

	}

	return tr;

}




double SquareOfTriangle(Triangle *tr){
       if (NULL == tr ) {
		return 0;
	}
if (TriangleIsRectangular(tr->A,tr->B,tr->C)==0){
    return 0;
}

 double a = lenghtLin(tr->A,tr->B);
 double b = lenghtLin(tr->B,tr->C);
 double c = lenghtLin(tr->C,tr->A);
 double  gipo=0;
 double kat1=0;
 double kat2=0;

 if (a>b) {gipo = a;}
    else { gipo =b;}
    if (gipo<c) {gipo=c;}

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

 double square=(kat1*kat2)/2;
 return square;
}


double PerimetrOfTriangle(Triangle *tr){
    if (TriangleIsRectangular(tr->A,tr->B,tr->C)==0){
    return 0;
}
  double a = lenghtLin(tr->A,tr->B);
 double b = lenghtLin(tr->B,tr->C);
 double c = lenghtLin(tr->C,tr->A);
 return a+b+c;
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
