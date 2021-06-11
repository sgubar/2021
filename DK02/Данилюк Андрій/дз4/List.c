#include "List.h"
#include <stdio.h>

listNode *createNode(char setname)
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	node->name = setname;
	node->next = NULL;
	return node;
}

list *createList(void)
{
    list *Head = (list *)malloc(sizeof(list));

	if (NULL != Head)
    {
	Head->head = NULL;
    memset(Head, 0, sizeof(list));
	}

	return Head;

}


void addfrontNode(list **List, char setname)
{
	listNode *frontNew = createNode(setname);
	frontNew->next = *List;
	*List = frontNew;
}

void addbackNode(list **Node, char setname)
{
	listNode *backNew = createNode(setname);
	listNode *tmp = *Node;
	while(tmp->next!=NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = backNew;

}

void addbtwNode(list **Node, char setname)
{
	listNode *tmp = *Node;
	while(tmp->next!=NULL)
	{
		listNode *tmptmp = tmp;
		tmp = tmp->next;
		if((int)tmp->name > (int)setname)
		{
			listNode *btwNew = createNode(setname);
			tmptmp->next = btwNew;
			btwNew->next = tmp;
			break;
		}
	}
}






void printAllList(list *List){
	listNode *Print = List->head;

while(Print != NULL){
	printf("\n%c",Print->name);
	Print = Print->next;
}
free(Print);
}

int NumberOfNodes(list *List)
{
    listNode *Print = List->head;
    int Num = 0;
    while(Print != NULL){
	Print = Print->next;
	Num++;
}
free(Print);
return Num;

}

void deleteSpecialNode(list *List, char setname)
{

    listNode *target = List->head;
    listNode *before = List->head;
    if(List->head->name == setname)
    {
        List->head = before->next;
        deleteNode(target);
    }
    else
    {
        while(target->name != setname) {
        before = target;
		target = target->next;
		if(target->next == NULL)
        {
            break;
        }
	}
	before->next = target->next;
	deleteNode(target);
    }



}
void deleteNode(listNode *Node)
{

    free(Node);
}

void FreeList(list *List)
{

    listNode *element = List->head;

	while(NULL != element) {
		listNode *tmp = element->next;
		deleteNode(element);
		element = tmp;
	}

	free(List);
}
