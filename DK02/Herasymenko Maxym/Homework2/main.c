#include <stdio.h>
#include <stdlib.h>
#include "point.h"//бібліотека з точками
#include "line.h"//бібліотека з лініями, довжиною сторони квадрата й площа квадрата

int main(int argc, const char * argv[])
{
    //задаємо такі координати, щоб відстань між точками була однакова, бо в нас квадрат
Point *p = createPoint(-2,6);//задаємо координати для першої точки
    printf("Point A: ");
    printPoint(p);
    printf("\n");

    printf("Point B: ");
    Point *copy = copyPoint(p);//за допомогою цією функції створюємо декілька точок(змінених копій)
    copy->x = 2;
    printPoint(copy);
    printf("\n");

    printf("Point C: ");
    Point *copy1 = copyPoint(p);
    copy1->y = 2;
    printPoint(copy1);
    printf("\n");

    printf("Point D: ");
    Point *copy2 = copyPoint(p);
    copy2->y = 2;
    copy2->x = 2;
    printPoint(copy2);
    printf("\n");

    printf("Square\n");
    Line *l = createLineByPoints(p,copy, copy1, copy2);//виводимо наші точки з прикріпленими лініями
    printLine(l);
    printf("is equal points: %d\n", isEqualPoints(p, copy, copy1, copy2));//перевірка на подібність точок
    printf("Length between two points: %f", lenghtLine(l));
    printf("\n");
    printf("S of square: %f\n", power(lenghtLine(l), 2));// S = a^2 => S = power(lenghtLine(l), 2)

    deletePoint(p);
	deletePoint(copy);
	deletePoint(copy1);
	deletePoint(copy2);
	deleteLine(l);

}
