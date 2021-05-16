#include "ABO.h"
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
	        printf("Введите 10 чисел:(после ввода числа - ENTER)\n");
	        setlocale(LC_ALL, "ENG");
	        while(i<=10){
		                  scanf("%f", &a);
		                  root = add(root, a);
		                  i++;
	                    }
	        
	        inorder(root);
	        float t;
	        setlocale(LC_ALL, "Rus");
	        printf("\nВведите элемент который хотите удалить: ");
	        setlocale(LC_ALL, "ENG");
	        scanf("%f", &t);
	        delete (root, t);
	        inorder(root);
	        freemem(root);
	        return 0;
          }
