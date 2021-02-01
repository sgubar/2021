#include "dk_tool.h"        // Всі необхідні бібліотеки підключені

#define MAX_NUMBER 4        // Розмір для задання масиву (на випадок якщо вам закортить попросити мене переробити код)

char masive[MAX_NUMBER + 1], arr[MAX_NUMBER];


int main(int argc, char* argv[])
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    printf ("Введите 8-миричное число: ");
    fgets (masive, 5, stdin);    

    printf("%d\n", limonchik(masive));      //Вибачте за назву, але нічого краще в 11 годин вечора в голову не прийшло

    system("pause");        // Пишу у віжуалці
    return 0;           // Повертаємо 0 як знак об успішності функції
}

// Оскільки пишу код у віжуалці іноді можете побачити scanf_s(); замість scanf();

