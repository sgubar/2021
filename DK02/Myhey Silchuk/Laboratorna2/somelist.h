#define somelist_h
#ifdef somelist_h
#include <stdio.h>
typedef struct list {
	int x;
	char *name;

	struct list *next;


}list;

list *createNode(int id, char *setname);
void addfrontNode(list **Node, int id, char *setname);
void addbackNode(list **Node, int id, char *setname);
void addbtwNode(list **Node, int idnew, char *setname);
int Start();
void printMaxWord(list *List, int max);
void printAllList(list *List);
int words(char *word);









#endif /* somelist_h */
