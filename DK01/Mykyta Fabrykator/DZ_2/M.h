#ifndef _M_H_
#define _M_H_

typedef struct _Point{
	float x;
	float y;
} Point;

typedef struct _F{
	Point a;
	Point b;
	Point c;
	float s;
} f;

void readNumber(int *a, int flag);
void area(f a[], int i);
int testing(f a[], int i);
void add(f a[], int i);
 
#endif
