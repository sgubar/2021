
#include "list.h"

int main(){

    //Створюємо двозв'язний список типу char
    CharList *list = createCharList();
    //друкуємо пустий список
    printCharList(list);
    printf("\n");
    //Додаємо елементи до колекції
    addCharValueToCharList(list,'H');
    addCharValueToCharList(list,'e');
    addCharValueToCharList(list,'l');
    addCharValueToCharList(list,'l');
    addCharValueToCharList(list,'o');
    addCharValueToCharList(list,' ');
    addCharValueToCharList(list,'w');
    addCharValueToCharList(list,'o');
    addCharValueToCharList(list,'r');
    addCharValueToCharList(list,'l');
    addCharValueToCharList(list,'d');
    addCharValueToCharList(list,'!');
    //Друкуємо результат для перевірки роботи програми
    printCharList(list);
    //Друкуємо кількість елементів у колекції
    printf("ELEMENTS-->%d",getSizeOfCharList(list));
    //Проводимо вставку елементів до колекції
    printf("\n");
    insertCharElementToCharListAtIndex(list,2,'i');
    insertCharElementToCharListAtIndex(list,1,'8');
    insertCharElementToCharListAtIndex(list,7,'y');
    insertCharElementToCharListAtIndex(list,9,';');
    insertCharElementToCharListAtIndex(list,10,'#');
    //Друкуємо результат та кількість елементів у коллекції для перевірки роботи програми
    printCharList(list);
    printf("ELEMENTS-->%d",getSizeOfCharList(list));
    printf("\n");
    //Видаляємо елементи колекції, але якщо ми хочемо зберегти саму колекцію
    removeAllCharElements(list);
    //Знову друкуємо колекцію для перевірки, чи все видалено?
    printCharList(list);
    //Перевіряємо кількість елементів у пустій колекції.
    printf("ELEMENTS-->%d",getSizeOfCharList(list));
    printf("\n");
    //Видаляємо пам'ять після роботи.
    deleteCharList(list);
    return 0;
}
