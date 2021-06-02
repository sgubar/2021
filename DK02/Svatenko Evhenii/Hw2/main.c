#include "Array.h"

int main()
{
    //Створюємо точки трикутника
    point* p1 = makePoint(0, 0);
    point* p2 = makePoint(8, 0);
    point* p3 = makePoint(0, 6);
    point* p4 = makePoint(0, 4);
    point* p5 = makePoint(3, 0);
    point* p6 = makePoint(0, 12);
    point* p7 = makePoint(9, 0);

    //Створюємо трикутники за точками, що створили раніше
    triangle* firstTriangle = makeTriangleByPoints(p1, p2, p3);
    triangle* secondTriangle = makeTriangleByPoints(p1, p4, p5);
    triangle* thirdTriangle = makeTriangleByPoints(p1, p6, p7);

    //Створюємо массив трикутників
    arrayTriangle* array = makeArray(3);

    //Виводимо на екран
    printArray(array);

    //Добавляємо створені трикутники у масив
    addTriangleToArray(array, firstTriangle);
    addTriangleToArray(array, secondTriangle);
    addTriangleToArray(array, thirdTriangle);

    //Виводимо на екран
    printArray(array);

    //Створюємо нові точки для нового трикутника
    point* p8 = makePoint(0, 16);
    point* p9 = makePoint(12, 0);

    //Створюємо четвертий трикутник
    triangle* fourthTriangle = makeTriangleByPoints(p1, p8, p9);

    //Вставляємо четвертий трикутник за індексом
    putTriangleAtIndex(array, fourthTriangle, 3);

    //Виводимо на екран
    printArray(array);

    //Звільняємо пам'ять
    deletePoint(p1);
    deletePoint(p2);
    deletePoint(p3);
    deletePoint(p4);
    deletePoint(p5);
    deletePoint(p6);
    deletePoint(p7);
    deletePoint(p8);
    deletePoint(p9);

    deleteTriangle(firstTriangle);
    deleteTriangle(secondTriangle);
    deleteTriangle(thirdTriangle);
    deleteTriangle(fourthTriangle);

    deleteArray(array);
    return 0;
}
