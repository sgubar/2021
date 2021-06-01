#include <stdio.h>
#include <stdlib.h>
#include "lib.c"

t_list *create_node(int set_i){

    t_list *node = (t_list *)malloc(sizeof(t_list));

        node -> i =set_i;

        node -> next = NULL;
        node -> prev = NULL;

        return node;
}

void push_front(t_list **list, int set_i){
    t_list *new_element = create_node(set_i);

    new_element ->next = *list;
    new_element ->next -> prev =new_element;
    *list = new_element;
}

void push_back(t_list **list, int set_i){
    t_list *new_element = create_node(set_i);

    t_list *tmp = *list;
    while(tmp->next != NULL){
        tmp = tmp-> next;
    }
    tmp->next = new_element;
    new_element->prev=tmp;
}

void del(t_list **list, int r){
    t_list *tmp= *list;
    t_list *tm=*list;
    t_list *t=NULL;
    for(int i=1;i<r;i++)
        tmp=tmp->next;
    for(int i=2;i<r;i++)
        tm=tm->next;
    if(tmp->next==NULL)
        tm->next=t;
    else
    tm->next=tmp->next;
    free(tmp);
}
