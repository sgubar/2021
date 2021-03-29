#include "M.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readNumber(int *a, int flag, int SIZE){
	int var, b=7, c=0;
	if (flag) b=SIZE;
	if (flag == 2){b=20; c=1;};
	do {
		var = scanf("%i", a);
		scanf("%*[^\n]");
		if (var==0 || *a>b || *a<c) printf("ERROR\nВведите корректное число: ");
	}while (var!=1 || *a>b || *a<c);
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

void creat_triangle(f t[]){
	int var = 0, flag = 0;
	t[0].a.x=t[0].a.y=t[0].b.x=t[0].b.y=t[0].c.x=t[0].c.y=t[0].s=0;
	float n[2];
	do{
		printf("\n");
		do{
			printf("Вершина A. Введите координаты (x y):\n");
			var = scanf("%f %f", &n[0], &n[1]);
			scanf("%*[^\n]");
		}while(var!=2);
		t[0].a = (*(Point*)(n));
		
		var = 0;
		do{
			printf("Вершина B. Введите координаты (x y):\n");
			var = scanf("%f %f", &n[0], &n[1]);
			scanf("%*[^\n]");
		}while(var!=2);
		t[0].b = (*(Point*)(n));
		
		var = 0;
		do{
			printf("Вершина C. Введите координаты (x y):\n");
			var = scanf("%f %f", &n[0], &n[1]);
			scanf("%*[^\n]");
		}while(var!=2);
		t[0].c = (*(Point*)(n));
		
		flag = testing(t, 0);
	}while(flag!=1);
}

f* creat_array(int SIZE){
	f* arr;
	arr = malloc(SIZE);
	int j=0 ;
	while(j<SIZE){
		arr[j].a.x=arr[j].a.y=arr[j].b.x=arr[j].b.y=arr[j].c.x=arr[j].c.y=arr[j].s=0;
		j++;
	}
	return arr;
}

void add(f a[], f t[]){
	int i=0;
	while(a[i].s!=0){
		i++;
	}
	a[i]=t[0];
}

void add_i(f a[], f t[], int i){
	a[i]=t[0];
}

void print_arr(f a[], int SIZE){
	int i=0;
	printf("\n\n");
	while(i<SIZE){
		printf("\nId: %d ", i);
		printf("\n   %0.2f %0.2f\n", a[i].a.x, a[i].a.y);
		printf("   %0.2f %0.2f\n", a[i].b.x, a[i].b.y);
		printf("   %0.2f %0.2f\n", a[i].c.x, a[i].c.y);
		printf("   Площадь: %0.2f\n", a[i].s);
		i++;
	}
	printf("\n\n");
}
