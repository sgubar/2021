#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct s_list {
    int i;

    struct s_list *next;
    struct s_list *prev;
}t_list;

int main(){
    int q=0;

    t_list *list = create_node(1);
    
    push_front(&list, 2);
    push_back(&list, 2);
    lab(&list);

    t_list *tmp = list;
    while (tmp->next != NULL){
        if(tmp->i==2){
            t_list *new_element = create_node(1000);
            new_element->next = tmp->next;
            new_element->prev= tmp;
            tmp->next = new_element;
            new_element->next->prev=new_element;
        }
        tmp = tmp -> next;
    }

    t_list *tmo = list;
    while (list != NULL) {
        q++;
        printf("%i= %i \n", q, list-> i);
        tmo = list;
        list = list -> next;
    }
printf("список в обратную сторону\n");
    while (tmo != NULL) {
        printf("%i= %i \n", q, tmo-> i);
        tmo = tmo -> prev;
        q--;
    }

    return 0;
}
