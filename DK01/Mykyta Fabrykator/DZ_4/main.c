#include "M2.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Rus");
    List *list = createList();
    int n;
    printf("Введите количество элементов[0; 50]\n");
    readNumber(&n, 1);
    while(n){
    	char a;
		printf("Введите элемент: ");
		scanf(" %c", &a);
    	pushBack(list, a);
    	n--;
	}
	int size = getSize(list);
	printf("%d\n\n", size);
	
	printHead(list);
	popBack(list);
	printHead(list);
	printf("\n\n");
	
	insert(list, 1, 'A');
	printHead(list);
	deleteIndex(list, 2);
	
    printHead(list);
    deleteList(&list);
    
	return 0;
}
