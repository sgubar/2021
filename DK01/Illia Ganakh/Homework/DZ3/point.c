#include "point.h"

Point *createPoint(int x, int y) {//створення точки
  Point *point = (Point *)malloc(sizeof(Point));
  if (NULL != point) {
    point->x = x;
    point->y = y;
  }
  return point;
}

Point *createPointByInput(Point *а) {
  Point *point = (Point *)malloc(sizeof(Point));
  if (NULL != point) {
    printf("введіть координату X:");
    scanf("%d", &point->x);
    printf("введіть координату Y:");
    scanf("%d", &point->y);
  }
  return point;
}

double lenght_Line(Point *a, Point *b) {//довжина лінії
  if (NULL == a || NULL == b) {
		return -1;
	}
  long dX = a->x - b->x;
  long dY = a->y - b->y;

  return sqrt(dX * dX + dY * dY);
}

int isEqualPoints(Point *a, Point *b) {//перевірка на однаковість точок
	if (NULL == a || NULL == b) {
		return 0;
	}
  if(a == b || (a->x == b->x && a->y == b->y)) {
    return 0;
  }
  return 1;
}

void printPoint(Point *p) {//вивід точки
  if (NULL == p) {
    return;
  }
  printf("(%2d, %2d)\n", p->x, p->y);
}

void deletePoint(Point *p) {//видалення точки
  if (NULL != p) {
    free(p);
  }
}