// tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include"tree.h"

int main(){
    
    IntTree* tree = createIntTree();






	insertIntValueToTree(tree, 23);

	insertIntValueToTree(tree, 12);

	insertIntValueToTree(tree, 15);

	insertIntValueToTree(tree, 9);

	insertIntValueToTree(tree, 3);

	insertIntValueToTree(tree, 27);

	insertIntValueToTree(tree, 32);

	insertIntValueToTree(tree, 47);

	insertIntValueToTree(tree, 56);


	



	printf("\n");

	printTree(tree);

	deleteNodeWithValue(tree, 12);
//
	deleteNodeWithValue(tree, 3);

	deleteNodeWithValue(tree, 34);

	printf("\n");

	printTree(tree);

	destroyIntTree(tree);

	return 0;		 

}
