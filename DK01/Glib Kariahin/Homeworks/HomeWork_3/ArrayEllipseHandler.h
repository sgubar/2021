//
// Created by 123 on 14.03.2021.
//

#ifndef HOMEWORKINFO_3_ARRAYELLIPSEHANDLER_H
#define HOMEWORKINFO_3_ARRAYELLIPSEHANDLER_H

#include <stdio.h>
#include "Ellipse.h"

#define ArrayLessThanZeroIndexError (-1)
#define ArrayNullPointerException (-2)
typedef struct tag_ArrayEllipse{
    Ellipse **storage;
    long count;
} ArrayEllipse;

ArrayEllipse *createArrayEllipse(long preservedCount);
void deleteArrayEllipse(ArrayEllipse *a);

int setEllipsetAtIndex(ArrayEllipse *a, Ellipse *value, int index);
Ellipse *getEllipseAtIndexOrNull(ArrayEllipse *a, int index);

void printArrayEllipse(ArrayEllipse *a);
long countArrayEllipse(ArrayEllipse *a);
int addNewEllipseToArray(ArrayEllipse *a, Ellipse *value);

#endif //HOMEWORKINFO_3_ARRAYELLIPSEHANDLER_H
