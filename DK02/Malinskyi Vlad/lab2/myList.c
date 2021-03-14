#include "myList.h"

List *input(int *listSize)
{
    do{
        printf("Enter list size(must be positive number):\n");
        scanf("%d", listSize);
    } while(*listSize <= 0);

    printf("Fill in the list: \n");
    int initValue;
    scanf("%d", &initValue);

    //List's head to be returned
    List *myList = init(initValue);
    if(*listSize == 1)
        return myList;
    List *iter = myList;

    if(*listSize > 1)
    {
        for(int i = 0; i < *listSize-1; i++)
        {
            int inputNumer;
            scanf("%d", &inputNumer);
            addelem(iter, inputNumer);
            iter = iter->next;
        }
    }
    else
    {
        return myList;
    }
    return myList;
}

void printList(List *myList)
{
    List *iter = myList;
    while(iter != NULL)
    {
        printf("%d ", iter->val);
        iter = iter->next;
    }
}

void freeList(List *head)
{
   List* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

void swapNodes(List *node1, List *node2)
{
    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;
}

List *addelem(List *lst, int number)
{
  List *temp, *p;
  temp = (List *)malloc(sizeof(List));
  p = lst->next; // сохранение указателя на следующий узел
  lst->next = temp; // предыдущий узел указывает на создаваемый
  temp->val = number; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий элемент
  return(temp);
}

List *init(int a)
{
  List *lst;
  // выделение памяти под корень списка
  lst = (List *)malloc(sizeof(List));
  lst->val = a;
  lst->next = NULL; // это последний узел списка
  return(lst);
}

