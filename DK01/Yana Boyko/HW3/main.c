#include <stdio.h>
#include "array.h"

int main()
{
    Array *array = createArray(3);

    printArray(array);

    append(array, createTriangleByPoints(createPoint(1, 0), createPoint(0, 0), createPoint(0, 1)));

    append(array, createTriangleByPoints(createPoint(2, 0), createPoint(0, 0), createPoint(2, 1)));

    appendByIndex(array, createTriangleByPoints(createPoint(2, 0), createPoint(0, 0), createPoint(0, 3)), 1);

    printArray(array);

    deleteArray(array);

    return 0;
}
