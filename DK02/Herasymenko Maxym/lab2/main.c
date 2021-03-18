#include "list.h"

int main(int argc, const char * argv[]) {
    int value, value1, value2;
    //input point A
    printf("A: ");
    while(scanf("%d", &value)==0)
    {
        printf("Please enter ONLY digits");
        return 0;
    }
    //input point B
    printf("B: ");
    while(scanf("%d", &value1)==0)
    {
        printf("Please enter ONLY digits");
        return 0;
    }
     //input point C
    printf("C: ");
    while(scanf("%d", &value2)==0)
    {
        printf("Please enter ONLY digits");
        return 0;
    }

	IntList *l = createList();

	addValueToList(l, value);//add number to point A
	addValueToList(l, value1);
	insertElementToList_Index(l, 1, value2);//add number to point C using index 1

	printf("Normal order: \n");
	printList(l);
	printf("Reverse order: \n");
	printReverse_order(l);

	deleteList(l);
}
