#include "filter.h"
#include <Windows.h>
#include <time.h>

int main()
{
    srand(6);                                           //  Генерируем пспевдорандом отталкиваять от сида
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list* spisok = make_list();
    for (int i = 0; i < 10; i++)
        add_value_to_list(spisok, rand() % 200 - 100);  //  Вводим рандомные значение от -100 до 100
    printf("Список до сортировки:\n");
    print_list(spisok);
    printf("Минимальное число: %d\n",minimum(spisok));
    qsort_after_min(spisok);
    printf("Список после сортировки:\n");
    print_list(spisok);  
    delete_list(spisok);
    system("pause");
    return 0;
}
