#ifndef single_list_h
#define single list_h

#include<stdio.h>
#include<stdlib.h>

typedef struct tagSingle_listCharElement Single_listCharElement;
struct tagSingle_listCharElement
{
    Single_listCharElement *next;
    char value;
};
Single_listCharElement *createSingle_listCharElement(char value);
void print_Single_listCharElement(Single_listCharElement *element);
void delete_Single_listCharElement(Single_listCharElement *element);

typedef struct tagCharSingle_list
{
    Single_listCharElement *head;
}CharSingle_list;

CharSingle_list *createCharSingle_list(void);
char addCharValue(CharSingle_list *list, char value);
char removeCharElementfromList_usingIndex(CharSingle_list *list, int index);
char insertCharElementtoList_usingIndex(CharSingle_list *list, int index, char value);
void deleteCharSingle_list(CharSingle_list *list);
long countCharSingle_list(CharSingle_list *list);
void printCharSingle_list(CharSingle_list *list);

void removeFirstCharElementfromList(CharSingle_list *list);
void removeLastCharElementfromList(CharSingle_list *list);
#endif // single_list_h

