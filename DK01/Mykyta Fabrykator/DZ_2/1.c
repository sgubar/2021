#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "M.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	f a[11];
	int j=0;
	while(j<10){
		a[j].a.x=a[j].a.y=a[j].b.x=a[j].b.y=a[j].c.x=a[j].c.y=a[j].s=0;
		j++;
	}
	int flag = 0;
	int n=-1;
	do{
		printf("Действия:\n 1 - Добавить треугольник\n 2 - Вывод треугольника по индексу\n");
		printf(" 3 - Вывод списка треугольников\n 4 - Удаление треугольника по индексу\n 5 - Очистить консоль\n 0 - EXIT\n");
		int i = 0;
		readNumber(&flag, 0);
		switch(flag){
			case 0:
				printf("EXIT");
				break;
			case 1:
				if (n<10){
					n++;
					add(a, n);
				}else printf("Максимальное количество треугольников\n");
				break;
			case 2:
				printf("\nВведите индекс[0;9]: ");
				readNumber(&i, 1);
				if (i>n) printf("\nНет информации\n\n");
				else{
					printf("\n\n%0.2f %0.2f\n", a[i].a.x, a[i].a.y);
					printf("%0.2f %0.2f\n", a[i].b.x, a[i].b.y);
					printf("%0.2f %0.2f\n", a[i].c.x, a[i].c.y);
					printf("Площадь: %0.2f\n\n", a[i].s);
			    }
				break;
			case 3:
				if (n==-1) printf("\nСписок пуст\n\n");
				i=0;
				printf("\n\n");
				while(i<=n){
					printf("Id: %d ", i);
					printf("Площадь: %0.2f\n", a[i].s);
					i++;
				}
				printf("\n\n");
				break;
			case 4:
				if (n==-1) printf("\nСписок пуст\n\n");
				else{
					printf("\nВведите индекс[0;9]: ");
					readNumber(&i, 1);
					while(i<=n){
						a[i]=a[i+1];
						i++;
					}
					n--;
				}
				break;
			case 5:
				system("cls");
				break;
		}
	}while(flag!=0);
	
	return 0;
}
