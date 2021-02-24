#include "tool.h"

#define MAX_NUMBER 8

int main(int argc, char* argv[])
{
    char masive[MAX_NUMBER + 1];

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Введіть 2-ричне число: ");
    fgets(masive, 9, stdin);
    printf("Його 10-ирична форма: %d\n", Convert_Oct_to_Dec(masive));

    system("pause");        
    return 0;           
}
