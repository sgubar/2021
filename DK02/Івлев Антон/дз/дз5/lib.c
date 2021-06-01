#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

t_list *create_node(int set_i){

    t_list *node = (t_list *)malloc(sizeof(t_list));

        node -> i =set_i;

        node -> left = NULL;
        node -> right = NULL;

        return node;
}

void push(t_list **list, int set_i){
        t_list *new_element = create_node(set_i);
        t_list *tmp = *list;
        while(tmp->left !=0 || tmp->right!=0){
            if(tmp->i >new_element->i)
                tmp=tmp->left;
            if(tmp->i < new_element->i)
                tmp=tmp->right;
        }
        if(tmp->i >new_element->i)
                tmp->left=new_element;
        if(tmp->i < new_element->i)
                tmp->right=new_element;
}

void treeprint(t_list **list) {
    t_list *tmp = *list;
  if (tmp!=NULL) { 
    printf("%i \n",tmp->i); 
    treeprint(&tmp->left); 
    treeprint(&tmp->right); 
  }
}

void freemem(t_list **list) {
    t_list *tmp = *list;
  if(tmp!=NULL) {
    freemem(&tmp->left);
    freemem(&tmp->right);
    free(tmp);
  }
}
