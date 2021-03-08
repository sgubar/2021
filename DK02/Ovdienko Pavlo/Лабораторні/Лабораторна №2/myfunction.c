#include "list.h"

int MaxmimumElementOfList(IntList* list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}
	if (list->head == NULL) {
		return 0;
	}

	ListNumbers* number;
	int MaxElement = 0;

	for (ListNumbers* number = list->head; number != NULL; number = number->next) {
		if (number->value > MaxElement) {
			MaxElement = number->value;
		}
	}
	return MaxElement;
}

void sortElementsOfList(IntList* list, int sizeList) {


    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }
    if (list->head == NULL) {
        return 0;
    }
    int maxEl = MaxmimumElementOfList(list);

    bool goaway = false;
    ListNumbers* number;
    ListNumbers* tmp;
    int change = 0;
    bool flag = 1;
    for (int i = 0; i < sizeList; i++)
    {
        goaway = false;
        while (flag == 1) {
            number = list->head;
            tmp = number->next;
            flag = 0;
            while (tmp) {



                if ((number->value) > (tmp->value)) {
                    change = number->value;
                    number->value = tmp->value;
                    tmp->value = change;
                    flag = 1;
                }
                else if ((number->value) == (tmp->value)) {
                    flag = 1;
                }
                number = number->next;
                tmp = tmp->next;

                if (maxEl == number->value) {
                    goaway = true;
                }
                if (goaway) {
                    break;
                }
            }
            if (goaway) {
                break;
            }
        }
    }

}