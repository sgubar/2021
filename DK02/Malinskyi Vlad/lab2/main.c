//09.03.2021 Laba_4 7th task

#include <stdio.h>
#include <stdlib.h>

#include "myList.h"
#include "Utils.h"

int main()
{
    //Intro
    printf("Laba#4, task - 7\n");

    int listSize;
    //Our list's head
    List *myList = input(&listSize);

    int separator;
    printf("Enter separator(List will be reversed between it's first and last occurrence): ");
    scanf("%d", &separator);

    if(isPresentedTwiceInList(myList, separator))
    {
        printf("Yout new list is - ");

        //"borders" between  which list will be reversed
        List* start = findStart(myList, separator);
        List* end = findEnd(myList, separator);

        //reverse
        changeOrder(start, end);
    }else
    {
        printf("No changes :(\n");
    }
    printList(myList);

    freeList(myList);

    return 0;
}
