#include "somelist.h"
#include <stdio.h>

list *createNode(int id, char *setname)
{	
	list *node = (list*)malloc(sizeof(list));
	node->x = id;
	node->name = setname;
	node->next = NULL;
	return node;
}

void addfrontNode(list **Node, int id, char *setname)
{
	list *frontNew = createNode(id, setname);
	frontNew->next = *Node;
	*Node = frontNew;
}

void addbackNode(list **Node, int id, char *setname)
{
	list *backNew = createNode(id, setname);
	list *tmp = *Node;
	while(tmp->next!=NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = backNew;
}

void addbtwNode(list **Node, int idnew, char *setname)
{
	list *tmp = *Node;
	while(tmp->next!=NULL)
	{
		list *tmptmp = tmp;
		tmp = tmp->next;
		if(tmp->x > idnew)
		{
			list *btwNew = createNode(idnew, setname);
			tmptmp->next = btwNew;
			btwNew->next = tmp;
			break;
		}
	}
}



int Start()
{
	char answer;
	int number = 0;
	do{
		answer == '0';
		printf("Do you want to create new list? Type Y or N down below\n");
		scanf(" %c", &answer);
		if(answer == 'Y' || answer == 'N')
		{
			if(answer == 'Y')
			{
				printf("How many words you wanna put into a list\n");
				do{
					scanf("%d", &number);
					if(number<=0)
					{
						printf("Invalid value\nWrite again\n");
					}
				}while(number<=0);
				return number;
				break;
			}
			else
			{
				printf("Ok, have a great day\n");
				return 0;
			}
		
		}
		if(answer != 'Y' && answer != 'N')
		{
			printf("Your answer isn't correct. Try again\n");
		}
	}while(answer!='Y' && answer!='N');
}

void printMaxWord(list *List, int max)
{
	while(List->x != max)
	{
		List = List->next;
		list *tmp = List->next;
		if( List->next !=NULL && tmp->x == max )
		{
			printf("%s\n", tmp->name );
		}
		
	}
}

void printAllList(list *List){
	int i = 1;
while(List != NULL){
	
	printf("%d.%s\n", i, List->name);
	List =List->next;
	i++;
}
}



int words(char *word)
{
	int i = 0;
	int id = 0;
	do{
		i++;
		id = i;	
	}while(word[i]!= NULL);
	return id;
}
