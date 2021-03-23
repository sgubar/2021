#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
	 int q;
    printf("enter\n");
    scanf("%d", &q);
 
    TNode* list = GetList(q);
    Print(list);
 do{
 
    RemoveEvery(&list, 3);
 
    Print(list);
    int s=q/3;
    q=q-s;
}while(q>2);
    return 0;
}
