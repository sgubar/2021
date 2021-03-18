//
// Created by 123 on 14.03.2021.
//
#include "replacer.h"
IntList* replace(IntList *list){

    IntList *list_2 = createIntList();
    IntListElement* elem = NULL;
    //addIntValueToIntList(list_2,list->tail->value);
    for (elem = list->tail; elem != list->head; elem = elem->prev) {
        addIntValueToIntList(list_2,elem->value);
    }
    return list_2;
}
