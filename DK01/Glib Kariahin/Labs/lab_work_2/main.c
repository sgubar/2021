//У списку переставити у зворотному порядку всі елементи проміж першим і останнім входженнями заданого елемента,
//якщо він входить у список не менше двох разів
#include "list.h"
#include "replacer.h"
#include "filler.h"
#include <stdlib.h>

int main(){

    //Створюємо двозв'язний список
    IntList *list = createIntList();
    //Генеруємо дані
    fill_in_with_random(list,56);
    //друкуємо результат генерації даних
    printIntList(list);
    //Проводимо заміну елементів та створюємо новий список, у який їх і записуємо.
    IntList* list_2 = replace(list);
    //Друкуємо результат для перевірки роботи програми
    printIntList(list_2);
    //Видаляємо пам'ять після роботи.
    deleteIntList(list);
    deleteIntList(list_2);

    return 0;
}
