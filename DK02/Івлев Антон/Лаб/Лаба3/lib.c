#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

t_list *create_node(float set_i){

    t_list *node = (t_list *)malloc(sizeof(t_list));

        node -> i =set_i;

        node -> left = NULL;
        node -> right = NULL;

        return node;
}

void push(t_list **list, float set_i){
        t_list *new_element = create_node(set_i);
        t_list *tmp = *list;
        while(tmp->left !=NULL || tmp->right!=NULL){
            if(tmp->i >new_element->i){
                if(tmp->left==NULL){
                tmp->left=new_element;
                
            }
                tmp=tmp->left;}
            else if(tmp->i < new_element->i){
                if(tmp->right==NULL){
                tmp->right=new_element;
                
            }
                tmp=tmp->right;}
        }
        if(tmp->i >new_element->i)
                tmp->left=new_element;
        else if(tmp->i < new_element->i)
                tmp->right=new_element;
}

void treeprint(t_list **list) {
    t_list *tmp = *list;
  if (tmp!=NULL) {  
    treeprint(&tmp->left); 
    treeprint(&tmp->right); 
    printf("%f \n",tmp->i);
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
