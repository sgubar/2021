#include "tree.h"
#include <stdio.h>

CharTree *createTree(void)
{
	CharTree *Tree = (CharTree*)malloc(sizeof(CharTree));
	if(Tree != NULL)
	Tree->root = NULL;
	Tree->count = 0;
}

CharTreeElement *createTreeElement(char symvol){
	CharTreeElement *TreeElement = (CharTreeElement*)malloc(sizeof(CharTreeElement));
	if(TreeElement != NULL)
	{
		TreeElement->left = NULL;
		TreeElement->right = NULL;
		TreeElement->symbol = symvol;
	}
	return TreeElement;
}

void PutElementToTheTree(CharTree *Tree, char symbol)
{
	CharTreeElement *TreeElement = createTreeElement(symbol);
	if(Tree->root == NULL)
	{
		Tree->root = TreeElement;
		printf("%c\n", symbol);
		Tree->count++;
	}
	else
	{
		CharTreeElement *NowElement = Tree->root;
		CharTreeElement *HighElement = NULL;
		while(1)
		{
			HighElement = NowElement;
			if(NowElement->symbol> symbol)
			{
				NowElement = NowElement->left;
				if(NowElement == NULL)
				{
				 	printf("Left\n");
				 	HighElement->left = TreeElement;
				 	printf("%d\n", symbol);
				 	break;
				}

			}
			else
			{
				NowElement = HighElement->right;
				if(NowElement == NULL)
				 {
				 	printf("Right\n");
				 	HighElement->right = TreeElement;
				 	printf("%d\n", symbol);
				 	break;
				 }

			}
		}
	Tree->count++;
	}
}
void printNode(CharTreeElement *Node)
{
	if(Node == NULL)
	{
		return;
	}
	printNode(Node->left);
	printNode(Node->right);
	printf("Element value is %c, %d\n", Node->symbol, Node->symbol);

}


void delTreeElement(CharTree *tree, char symbol)
{

	CharTreeElement *NowElementIs = tree->root;
	CharTreeElement *HighElement = NULL;
	if(NowElementIs->symbol == symbol)
	{
		tree->root = NULL;
		printf("First node was deleted & tree disappeared");
		return;
	}
	while(NowElementIs->left!=NULL || NowElementIs->right!=NULL)
	{
			if(NowElementIs->symbol> symbol)
			{
				HighElement = NowElementIs;
				if(NowElementIs->symbol != symbol)
			 	{
			 		NowElementIs = NowElementIs->left;
					printf("Value is %d r\n", HighElement->symbol);
					printf("Go far %c, %d l\n", NowElementIs->symbol,NowElementIs->symbol);
			 	}
				if(NowElementIs->symbol == symbol)
				{
                        HighElement->left = NULL;
						printf("Deleted l\n");
			 			break;

				}
			}
			if(NowElementIs->symbol< symbol)
			{
				HighElement = NowElementIs;
				if(NowElementIs->symbol != symbol)
				{
			 		NowElementIs = NowElementIs->right;
					printf("Value is %d r\n", HighElement->symbol);
					printf("Go far %c, %d r\n", NowElementIs->symbol,NowElementIs->symbol);
				}
				if(NowElementIs->symbol == symbol)
				{
                        HighElement->right = NULL;
						printf("Deleted r\n");
			 			break;
			 	}
			}

	}
}


void freeNode(CharTreeElement *Node)
{
	if(Node != NULL)
	{

	freeNode(Node->left);
	freeNode(Node->right);

	free(Node);
}
}




void freeTree(CharTree *Tree)
{
	if(Tree != NULL)
	{
	freeNode(Tree->root);
	free(Tree);
}
return 0;
}

void printTree(CharTree *Tree)
{
	CharTreeElement *Current = Tree->root;
	printNode(Current);
}
