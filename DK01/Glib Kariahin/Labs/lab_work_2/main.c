//У списку переставити у зворотному порядку всі елементи проміж першим і останнім входженнями заданого елемента,
//якщо він входить у список не менше двох разів
#include "list.h"
#include "replacer.h"
#include <stdlib.h>

int main(){

    //Створюємо двозв'язний список
    IntList *list = createIntList();
    //Генеруємо дані
    int a = rand()%100;

    for(int x = 0;x<a;x++){
        addIntValueToIntList(list,rand()%100);
    }
    //друкуємо результат генерації даних
    printIntList(list);
    //Проводимо заміну елементів та створюємо новий список, у який їх і записуємо.
    IntList* list_2 = replace(list);
    //Друкуємо результат для перевірки роботи програми
    printIntList(list_2);
    //Видаляємо пам'ять після роботи.
    while(!(list_2->head==NULL)){
        removeLastElementFromIntList(list_2);
    }
    deleteIntList(list);
    deleteIntList(list_2);

    return 0;
}
