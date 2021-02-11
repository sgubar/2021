#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"
#include <string.h>



int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char arr[100];
	do
	{
		printf("Введите шестнадцетиричное число : \n");
		fgets(arr, 5, stdin);
	} while (peretvorenna_chisla(arr) == -1);
	printf("Выводим десятичное число %d \n ", peretvorenna_chisla(arr));
    return 0;
}

