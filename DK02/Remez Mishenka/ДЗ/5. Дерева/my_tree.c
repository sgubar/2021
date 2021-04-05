#include "tree.h"

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	tree* derevce = make_tree();
	include_item_im_tree(derevce, 0.4);
	include_item_im_tree(derevce, 0.3);
	include_item_im_tree(derevce, 0.7);
	include_item_im_tree(derevce, 0.1);
	include_item_im_tree(derevce, 0.6);
	include_item_im_tree(derevce, 0.2);
	include_item_im_tree(derevce, 0.9);

	print_tree(derevce);		//	Выводит согласно симетричному обходу

	printf("\n");

	delete_item_from_tree(derevce, 0.7);

	print_tree(derevce);

	printf("\nПроверка функции поиска числа 0.2: %0.1f\n", find_tree_item(derevce, 0.2)->value);

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

