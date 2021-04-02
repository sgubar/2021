#include "M3.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Rus");
	node* root = create(root, 0);
	float a;
	int i=1;
	printf("Введите 10 чисел(после ввода числа нажимаем enter):\n");
	setlocale(LC_ALL, "ENG");
	while(i<=10){
		scanf("%f", &a);
		root = add(root, a);
		i++;
	}
	
	inorder(root);
	freemem(root);
	return 0;
}
