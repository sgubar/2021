#ifndef tree_h
#define tree_h
#include <stdio.h>




typedef struct TreeElement{

	char symbol;
	struct CharTreeElement *left;
	struct CharTreeElement *right;

}CharTreeElement;

typedef struct CharTree{
	struct TreeElement *root;
	int count;
}CharTree;


static void printNode(CharTreeElement *Node);
static void freeNode(CharTreeElement *Node);

CharTree *createTree(void);
CharTreeElement *createTreeElement(char symvol);
void PutElementToTheTree(CharTree *Tree, char symbol);
void delTreeElement(CharTree *tree, char symbol);
void freeNode(CharTreeElement *Node);
void freeTree(CharTree *Tree);
void printNode(CharTreeElement *Node);
void printTree(CharTree *Tree);






#endif /* tree_h */
