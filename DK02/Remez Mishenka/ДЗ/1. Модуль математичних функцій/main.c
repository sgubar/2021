#include "dk_tool.h"

#define MAX_NUMBER 4

int main(int argc, char* argv[])
{
    char masive[MAX_NUMBER + 1];

    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    printf ("Введите 8-иричное число: ");
    fgets (masive, 5, stdin);    
    printf("Его 10-иричная форма: %d\n", Convert_Oct_to_Dec(masive));   

    system("pause");        // Пишу у віжуалці
    return 0;           // Повертаємо 0 як знак об успішності функції
}

// Оскільки пишу код у віжуалці іноді можете побачити scanf_s(); замість scanf();

