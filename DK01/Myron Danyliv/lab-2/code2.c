#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _Node {
                     int value;
                     struct _Node *next;
                     struct _Node *prev; 
                     } Node;

typedef struct _List {
                     int size;
                     Node *head;
                     Node *tail;
                     } List;

List* createList() {
                   List *temp = (List*) malloc(sizeof(List));
                   temp->size = 0;
                   temp->head = temp->tail = NULL;
 
                   return temp;
                   }

void deleteList(List **list) {
                             Node *temp = (*list)->head;
                             Node *next = NULL;
                             while (temp) {
                                          next = temp->next;
                                          free(temp);
                                          temp = next;
                                          }
                             free(*list);
                             (*list) = NULL;
                             }

void add(List *list, int value){
                               Node *temp = (Node*) malloc(sizeof(Node));
                               temp->next=NULL;
                               temp->value=value;
                               if (list->head != NULL){
                                                      temp->prev = list->tail;
                                                      (list->tail)->next = temp;
                                                      list->tail = temp;
                                                      }else{
                                                           temp->prev = NULL;
                                                           list->head = list->tail = temp;
                                                           }
                                                      }

void printTail(List *list) {
                           Node *temp = list->tail;
                           while (temp) {
                                        printf("%d ", temp->value);
                                        temp = temp->prev;
                                        }
                           printf("\n");
                           }

void printHead(List *list) {
                           Node *temp = list->head;
                           while (temp) {
                                        printf("%d ", temp->value);
                                        temp = temp->next;
                                        }
                           printf("\n");
                           }

void readNumber(int *a, int flag){
	                               int var, b=-50;
	                               if(flag) b=0;
	                               do {
		                                var = scanf("%i", a);
		                                scanf("%*[^\n]");
		                                if (var==0 || *a>50 || *a<b) printf("ERROR\nВведите корректное число: ");
	                                  }while (var!=1 || *a>50 || *a<b);
                                 }

int main() {
	         setlocale(LC_ALL, "Rus");
           List *list = createList();
           int n;
           printf("Введите количество чисел[0; 50]\n");
           readNumber(&n, 1);
           while(n){
    	             int a=0;
		               printf("Введите число[-50; 50]: ");
		               readNumber(&a, 0);
    	             add(list, a);
    	             n--;
	                 }
	         printHead(list);
	         printHead(list);
           printTail(list);
           printTail(list);
           deleteList(&list);
    
           return 0;
           }
