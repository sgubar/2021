#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct s_list {
    int i;

    struct s_list *left;
    struct s_list *right;
}t_list;

int main(){
    t_list *list = create_node(4);
    push(&list, 5);
    treeprint(&list);
}
