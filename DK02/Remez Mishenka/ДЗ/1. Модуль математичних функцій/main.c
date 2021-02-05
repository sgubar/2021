#include "dk_tool.h"        // Всі необхідні бібліотеки підключені

#define MAX_NUMBER 4        // Розмір для задання масиву (на випадок якщо вам закортить попросити мене переробити код)




int main(int argc, char* argv[])
{
    char masive[MAX_NUMBER + 1], arr[MAX_NUMBER];
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    printf ("Введите 8-миричное число: ");
    fgets (masive, 5, stdin);    

    printf("%d\n", Convert_Oct_to_Dec(masive));     

    system("pause");        // Пишу у віжуалці
    return 0;           // Повертаємо 0 як знак об успішності функції
}

// Оскільки пишу код у віжуалці іноді можете побачити scanf_s(); замість scanf();

