#include <stdio.h>
#include <Windows.h>
#include "List.h"

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list_float* flist = make_list();
	
	add_data_to_list(flist, 0.5);
	add_data_to_list(flist, 0.6);
	add_data_to_list(flist, 0.7);
	add_data_to_list(flist, 0.8);
	add_data_to_list(flist, 0.9);
	add_data_to_list_by_index(flist, 0, 0.4);

	print_list(flist);

	remove_data_by_index(flist, 2);

	print_list(flist);

	delete_list(flist);
}
