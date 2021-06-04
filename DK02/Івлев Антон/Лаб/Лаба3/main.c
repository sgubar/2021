#include <stdio.h>
#include <stdlib.h>
#include "lid.h"

typedef struct s_list {
    float i;

    struct s_list *left;
    struct s_list *right;
}t_list;

int main(){
    int o;
    float i;
    printf("Из скольки символов должно состоять дерево: ");
    scanf("%i", &o);
    printf("Вершина дерева: ");
    scanf("%f", &i);
    t_list *list = create_node(i);
    for(int p=1; p<o; p++){
        float u;
        printf("Новый елемент дерева: ");
        scanf("%f", &u);
        push(&list, u);
    }
    treeprint(&list);
}
