#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"

char arr[5];

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите шестнадцетиричное число : \n");
	fgets(arr, 5, stdin);
	printf("Выводим десятичное число %d \n ", just(arr));
    return 0;
}

