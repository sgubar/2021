#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
    t_list *list = create_node(4);
    push(&list, 5);
    treeprint(&list);
}
