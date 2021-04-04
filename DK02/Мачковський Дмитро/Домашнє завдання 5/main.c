#include <stdio.h>
#include "charTree.h"

int main(int argc, const char* argv[]) {

	CharTree* tree = createCharTree();
	insertCharValueToTree(tree, 'd');
	insertCharValueToTree(tree, 'f');
	insertCharValueToTree(tree, 'g');
	insertCharValueToTree(tree, 'a');
	insertCharValueToTree(tree, 'c');
	insertCharValueToTree(tree, 'b');
	insertCharValueToTree(tree, 'A');
	insertCharValueToTree(tree, 'D');
	insertCharValueToTree(tree, 'e');
	printTree(tree);
	deleteNodeWithValue(tree, 'e');
	printTree(tree);

	destroyCharTree(tree);

	return 0;
	//			   (d(100))
	//			   /         \
	//		  (a(97))          (f(102))
	//		    /    \           /      \
	//	     (A(65))  (c(99))   (e(101)) (g(103))
	//	        \       /  
	//        (D(68))  (b(98)) 
	//  			   
	//		
}
