#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "M.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	int SIZE = 0;
	printf("Введите размер массива[1;20]: ");
	readNumber(&SIZE, 2, 0);
	f triangle[1];
	f* a=creat_array(SIZE);
	int j=0;
	int flag = 0;
	int n=-1;
	do{
		printf("Выберите действие:\n 1 - добавление треугольника по индексу\n 2 - Добавление треугольника\n 3 - Вывод треугольника по индексу\n");
		printf(" 4 - Вывод списка треугольников\n 5 - Удаление треугольника по индексу\n 6 - Вывод массива\n 7 - Очистить консоль\n 0 - EXIT\n");
		int i = 0;
		readNumber(&flag, 0, 0);
		switch(flag){
			case 0:
				printf("EXIT");
				free(a);
				break;
			case 1:
				if (n<SIZE-1) n++;
				printf("\nВведите индекс[0;%d]: ", SIZE-1);
				readNumber(&i, 1, SIZE-1);
				creat_triangle(triangle);
				add_i(a, triangle, i);
				break;
			case 2:
				if (n<SIZE-1){
					n++;
					creat_triangle(triangle);
					add(a, triangle);
				}else printf("Максимальное количество треугольников\n");
				break;
			case 3:
				printf("\nВведите индекс[0;%d]: ", SIZE-1);
				readNumber(&i, 1, SIZE-1);
				if (i>n) printf("\nИнформации нет\n\n");
				else{
					printf("\n\n%0.2f %0.2f\n", a[i].a.x, a[i].a.y);
					printf("%0.2f %0.2f\n", a[i].b.x, a[i].b.y);
					printf("%0.2f %0.2f\n", a[i].c.x, a[i].c.y);
					printf("Площадь: %0.2f\n\n", a[i].s);
			    }
				break;
			case 4:
				if (n==-1) printf("\nСписок пуст\n\n");
				i=0;
				printf("\n\n");
				while(i<=SIZE-1){
					if(a[i].s!=0){
						printf("Id: %d ", i);
					    printf("Площадь: %0.2f\n", a[i].s);
					}
					i++;
				}
				printf("\n\n");
				break;
			case 5:
				if (n==-1) printf("\nСписок пуст\n\n");
				else{
					printf("\nВведите индекс[0;%d]: ", SIZE-1);
					readNumber(&i, 1, SIZE-1);
					while(i<=n){
						a[i]=a[i+1];
						i++;
					}
					n--;
				}
				break;
			case 6:
				print_arr(a, SIZE);
				break;
			case 7:
				system("cls");
				break;
		}
	}while(flag!=0);
	
	return 0;
}
