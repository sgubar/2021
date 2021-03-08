#include "filter.h"

int minimum(list* list)
{
	int cnt = count_of_items(list);
	int min = 2147483647;
	list_item* item = list->first;
	for (int i = 0; i < cnt; i++)
	{
		if (item->val < min)
			min = item->val;
		item = item->next_item;
	}
	return min;
}

void qsort_after_min(list* _list)
{	
	int buffer;
	int cnt = count_of_items(_list);
	int min = minimum(_list);
	int cnt2 = 4;			 // Чисто щоб пропустив ітерацію вайлу
	if (_list->last->val == min)
		return;
	list_item* item = make_list_item(0);


	while(cnt2 > 1)
	{
		for (item = _list->first; item->val != min; item = item->next_item);		//	Проходим все значения до минимального
		item = item->next_item;
		list* new_list = make_list();		
		new_list->first = item;
		new_list->last = _list->last;
		cnt2 = count_of_items(new_list);
		//printf("\n %d \n", cnt2);
		min = minimum(new_list);
		//printf("\n %d \n", min);

		//print_list(new_list);

		if (item->val != min)
		{
			buffer = item->val;
			item->val = min;
			for (item = new_list->first->next_item; item->val != min; item = item->next_item);
			item->val = buffer;
		}
		
		//print_list(_list);
	}

}