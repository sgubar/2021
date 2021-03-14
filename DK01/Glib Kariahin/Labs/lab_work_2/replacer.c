//
// Created by 123 on 14.03.2021.
//
#include "replacer.h"
IntList* replace(IntList *list){
    IntList *list_2 = createIntList();

    while(!(list->head==NULL)){
        addIntValueToIntList(list_2,list->tail->value);
        removeLastElementFromIntList(list);
    }
    return list_2;
}
