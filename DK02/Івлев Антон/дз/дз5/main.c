#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
    t_list *list = create_node(1);
    push(&list, 2);
    treeprint(&list);
}
