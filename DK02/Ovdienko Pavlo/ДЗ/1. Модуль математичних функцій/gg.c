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
	do
	{
		printf("Введите шестнадцетиричное число : \n");
		fgets(arr, 5, stdin);
	}
	while (just(arr)==-1);
	    printf("Выводим десятичное число %d \n ", just(arr));
    return 0;
}

