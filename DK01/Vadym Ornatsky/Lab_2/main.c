#include <stdio.h>
#include <string.h>
#include "linked_list.h"

// Maximum length of string to add = 2047 characters

int main() {
    T_ListNode* stringsList = NULL;
    T_ListNode* lastNode = NULL;
    unsigned int maxLength = 0;
    char inputString[2048];

    /* Input and initial sorting part */
    for (;;) {
        printf("Enter next string or \"stop\" to end input:\n");
        scanf("%s", inputString);
        if (!strcmp(inputString, "stop")) {
            printf("All data entered\n\n");
            break;
        }
        int strLength = strlen(inputString) + 1;
        if (strLength > maxLength) {
            maxLength = strLength;
        }
        if (NULL != stringsList) {
            if (strLength < stringsList->dataLength) {
                stringsList = InsertBefore(stringsList, inputString, strLength);
                if (NULL == stringsList) {
                    printf("Error in memory allocation");
                    return 1;
                }
            } else {
                T_ListNode* nodeToCompare = stringsList;
                while (nodeToCompare) {
                    if (strLength < nodeToCompare->dataLength) {
                        T_ListNode* insertedNode = InsertBefore(nodeToCompare, inputString, strLength);
                        if (NULL == insertedNode) {
                            printf("Error in memory allocation");
                            return 1;
                        }
                        break;
                    }
                    if (NULL == nodeToCompare->next) {
                        T_ListNode* insertedNode = InsertAfter(nodeToCompare, inputString, strLength);
                        if (NULL == insertedNode) {
                            printf("Error in memory allocation");
                            return 1;
                        }
                        lastNode = insertedNode;
                        break;
                    }
                    nodeToCompare = nodeToCompare->next;
                }
            }
        } else {
            stringsList = InitNode(inputString, strLength);
            lastNode = stringsList;
        }
    }

    /* Output Part */
    if (NULL == lastNode) {
        printf("No strings in list.");
        return 0;
    }
    T_ListNode* node = lastNode;
    printf("Longest string(s):\n");
    while (node && (node->dataLength == maxLength)) {
        printf("%s\n", node->data);
        node = node->previous;
    }
    if (stringsList) {
        FreeList(stringsList);
    }
    return 0;
}