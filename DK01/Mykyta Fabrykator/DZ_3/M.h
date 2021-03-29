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

void readNumber(int *a, int flag, int SIZE);
void area(f a[], int i);
int testing(f a[], int i);
void creat_triangle(f t[]);
void add(f a[], f t[]);
void add_i(f a[], f t[], int i);
void print_arr(f a[], int SIZE);
 
#endif
