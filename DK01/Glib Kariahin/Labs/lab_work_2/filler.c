//
// Created by 123 on 15.03.2021.
//
#include <stdlib.h>
#include "list.h"

void fill_in_with_random(IntList *list,int num_of_iterations){
    for(int x = 0;x<num_of_iterations;x++){
        addIntValueToIntList(list,rand()%100);
    }
}