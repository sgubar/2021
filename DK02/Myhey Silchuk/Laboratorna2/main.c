#include <stdio.h>
#include <stdlib.h>
#include "somelist.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int a = Start(); 
if(a != 0){
int idnew = 0;
int min = idnew, max = idnew;
printf("Enter a word:\n");
char word[a][20];
list *NewNode = createNode(idnew, "start");
for(int i =0; i<a; i++)
{	
	scanf("%s", &word[i]);
	idnew = words(word[i]);
	
	if(min>idnew)
	{
		addfrontNode(&NewNode, idnew, &word[i]);
		min = idnew;
	}
	if(max<=idnew)
	{
		addbackNode(&NewNode, idnew, &word[i]);
		max = idnew;
	}
	if(max>idnew && min<=idnew)
	{
		addbtwNode(&NewNode, idnew, &word[i]);
	}
}
NewNode = NewNode->next;
printf("Entire list of words:\n");
printAllList(NewNode);
printf("List of max words:\n");
printMaxWord(NewNode, max);
free(NewNode);
	return 0;
}

}
