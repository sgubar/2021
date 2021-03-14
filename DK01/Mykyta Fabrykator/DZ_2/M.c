#include "M.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readNumber(int *a, int flag){
	int var, b=5;
	if (flag) b=9;
	do {
		var = scanf("%i", a);
		scanf("%*[^\n]");
		if (var==0 || *a>b || *a<0) printf("ERROR\nВведите корректное число: ");
	}while (var!=1 || *a>b || *a<0);
}

void area(f a[], int i){
	float a1, b, c, d, dl;
	a1 = a[i].a.x - a[i].c.x;
	b = a[i].a.y - a[i].c.y;
	c = a[i].b.x - a[i].c.x;
	d = a[i].b.y - a[i].c.y;
	dl = a1*d - c*b;
	a[i].s = 0.5*fabsf(dl);
}

int testing(f a[], int i){
	area(a, i);
	if (a[i].s<=0){
		printf("Треугольник не существует\n\n");
		return 0;
	}else{
		printf("Треугольник добавлен\n\n");
		return 1;
	}
}

void add(f a[], int i){
	int var = 0, flag = 0;
	float n[2];
	do{
		printf("\n");
		do{
			printf("Вершина A. Введите координаты (x y):\n");
			var = scanf("%f %f", &n[0], &n[1]);
			scanf("%*[^\n]");
		}while(var!=2);
		a[i].a = (*(Point*)(n));
		
		var = 0;
		do{
			printf("Вершина B. Введите координаты (x y):\n");
			var = scanf("%f %f", &n[0], &n[1]);
			scanf("%*[^\n]");
		}while(var!=2);
		a[i].b = (*(Point*)(n));
		
		var = 0;
		do{
			printf("Вершина C. Введите координаты (x y):\n");
			var = scanf("%f %f", &n[0], &n[1]);
			scanf("%*[^\n]");
		}while(var!=2);
		a[i].c = (*(Point*)(n));
		
		flag = testing(a, i);
	}while(flag!=1);
}
