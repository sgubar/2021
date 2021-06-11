#define List_h
#ifdef List_h
#include <stdio.h>

typedef struct listNode {
	char *name;

	struct listNode *next;


}listNode;

typedef struct list{

    listNode *head;

}list;


listNode *createNode(char setname);
list *createList(void);
void addfrontNode(list **Node,char setname);
void addbackNode(list **Node,  char setname);
void addbtwNode(list **Node, char setname);
void deleteNode(listNode *Node);
void deleteSpecialNode(list *List, char setname);
void printAllList(list *List);
int NumberOfNodes(list *List);
void FreeList(list *List);
#endif
