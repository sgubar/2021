#include "point.h"

Point *createPoint() {//створення точки
  Point *point = (Point *)malloc(sizeof(Point));
  if (NULL != point) {
    printf("введіть координату X:");
    scanf("%d", &point->x);
    printf("введіть координату Y:");
    scanf("%d", &point->y);
  }
  return point;
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

