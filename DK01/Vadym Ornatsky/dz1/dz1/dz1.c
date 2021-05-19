#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	char string[100];
	unsigned int result = 0;
	printf("Vvedite chislo v dvoichnom vide (maks 8 simvolov) \n");
	scanf("%s", string);
	for (int i = 0; i < 8 && string[i] != 0; ++i) {
		result <<= 1;
		result += string[i] - '0';
	}
	printf("Result: %u \n", result); 
}

