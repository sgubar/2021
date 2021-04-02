#include "tree.h"

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	tree* derevce = make_tree();
	include_item_im_tree(derevce, 'D');
	include_item_im_tree(derevce, 'C');
	include_item_im_tree(derevce, 'H');
	include_item_im_tree(derevce, 'A');
	include_item_im_tree(derevce, 'F');
	include_item_im_tree(derevce, 'B');
	include_item_im_tree(derevce, 'L');

	print_tree(derevce);		//	Выводит согласно симетричному обходу

	printf("\n");

	delete_item_from_tree(derevce, 'L');

	print_tree(derevce);

	delete_tree(derevce);

	system("pause");
}


/*
 
    (D)
    / \
  (C) (H)
  /   / \
(A) (F) (L)
  \  
  (B) 

*/

