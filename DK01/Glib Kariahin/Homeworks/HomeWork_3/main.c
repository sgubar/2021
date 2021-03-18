#include "ArrayEllipseHandler.h"
#include "Ellipse.h"

int main() {

    // Ініціалізуємо список(коллекцію) еліпсів, з початковою кількістю в 4 елементи,
    // та додаткові умов створення еліпсів(створюємо фокуси для еліпсів) та безпосередньо самі еліпси.
    ArrayEllipse* arr = createArrayEllipse(4);
    printArrayEllipse(arr);
    Point* f1 = createPoint(5,0);
    Point* f2 = createPoint(-5,0);

    Ellipse* e1 = createEllipseByCoords(5,-5,13,12);
    Ellipse* e2 = createByFocusesEllipse(f1,f2,13,12);
    Ellipse* e3 = createEllipseByCoords(9,-9,41,40);
    Ellipse* e4 = createEllipseByCoords(16,-16,65,63);
    //Кінець ініціалізації для тесту
    printf("Count of elements :  %d\n",countArrayEllipse(arr));
    //Перевіряємо кількість елементів у коллекції.

    //Додаємо елементи до коллекції кожен на нову позицію автоматично.
    addNewEllipseToArray(arr,e3);
    addNewEllipseToArray(arr,e2);
    addNewEllipseToArray(arr,e3);
    addNewEllipseToArray(arr,e4);


    //Знову перевіряємо кількість елементів у коллекції.

    printf("Count of elements :  %d\n",countArrayEllipse(arr));

    //Друкуємо елементів у коллекції.
    printArrayEllipse(arr);

    //Друкуємо елементів у коллекції.
    Ellipse* e_1 = createEllipseByCoords(48,-48,73,55);
    Ellipse* e_2 = createEllipseByCoords(36,-36,97,72);
    Ellipse* e_3 = createEllipseByCoords(36,-36,85,77);


    //Замінюємо деякі елементи у коллекції для перевірки функціоналу.
    printf("Count of elements :  %d\n",countArrayEllipse(arr));
    setEllipsetAtIndex(arr,e_1,1);
    setEllipsetAtIndex(arr,e_2,3);
    setEllipsetAtIndex(arr,e_3,5);

    //Знову перевіряємо кількість елементів у коллекції та саму коллекцію, друкуючи її.
    printf("Count of elements :  %d\n",countArrayEllipse(arr));

    //Знову перевіряємо кількість елементів у коллекції.

    printf("Count of elements :  %d\n",countArrayEllipse(arr));
    printf("Release memory");

    //Зачищаємо пам'ять коллекції та її елементів.
    deletePoint(f1);
    deletePoint(f2);

    deleteEllipse(e1);
    deleteEllipse(e2);
    deleteEllipse(e3);
    deleteEllipse(e4);
    deleteEllipse(e_1);
    deleteEllipse(e_2);
    deleteEllipse(e_3);
    deleteArrayEllipse(arr);


    return 0;
}
