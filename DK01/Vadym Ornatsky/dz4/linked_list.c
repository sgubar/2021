#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

T_ListNode* InitNode(double value_) {
    T_ListNode* newNode = (T_ListNode*) malloc(sizeof(T_ListNode));
    if (NULL == newNode) {
        printf("Error: memory allocation\n");
        return NULL;
    }
    newNode->value = value_;
    newNode->next = NULL;
    return newNode;
}

T_ListNode* CreateList(double value_) {
    return InitNode(value_);
}

T_ListNode* AddToList(T_ListNode* list_, double value_) {
    if (NULL == list_) {
        return CreateList(value_);
    }
    T_ListNode* newNode = InitNode(value_);
    if (NULL == newNode) {
        printf("Error: memory allocation\n");
        return NULL;
    }
    newNode->next = list_->next;
    list_->next = newNode;
    return newNode;
}

T_ListNode* RemoveFromListByIndex(T_ListNode* list_, unsigned int index_) {
    if (NULL == list_) {
        printf("Error: can't remove node from empty list\n");
        return 0;
    }
    if (0 == index_) {
        if (NULL == list_->next) {
            DestroyList(list_);
            return NULL;
        } else {
            // copy element 1 to head, remove element 1. For not freeng pointer to head of list owned by main app
            T_ListNode* toDelete = list_->next;
            list_->next=toDelete->next;
            list_->value=toDelete->value;
            free(toDelete);
            return list_;
        }
    }
    unsigned int currentIndex = 0;
    T_ListNode* node = list_;
    T_ListNode* previous = list_;
    while (node) {
        if (currentIndex == index_) {
            previous->next = node->next;
            free(node);
            return previous;
        }
        previous = node;
        node = node ->next;
        currentIndex++;
    }
    printf("Error: index of element to remove is larger then list size\n");
    return NULL;
}

T_ListNode* InsertByIndex(T_ListNode* list_, unsigned int index_, double value_) {
    if (NULL == list_) {
        printf("Can't insert value = %f in position %u. List is empty, creating new one\n", value_, index_);    
        return CreateList(value_);
    }
    unsigned int currentIndex = 0;
    unsigned int insertedOk = 0;
    T_ListNode* node = list_;
    T_ListNode* lastNode = list_;
    while (node) {
        if (currentIndex == index_) {
            T_ListNode* newNode = InitNode(node->value);
            if (NULL == newNode) {
                printf("Error: memory allocation\n");
                return NULL;
            }
            newNode->next = node->next;
            node->next = newNode;
            node->value = value_;
            return newNode;
        }
        lastNode = node;
        node = node ->next;
        currentIndex++;
    }
    printf("Index to insert is larger then list size. Node will be appended to list\n");
    T_ListNode* newNode = InitNode(value_);
    if (NULL == newNode) {
        printf("Error: memory allocation\n");
        return NULL;
    }
    newNode->next = NULL;
    lastNode->next = newNode;
    return newNode;
}


void DestroyList(T_ListNode* list_) {
    if (NULL == list_) {
        return;
    }
    T_ListNode* node = list_;
    while (node) {
        T_ListNode* nodeToClear = node;
        node = node ->next;
        free(nodeToClear);
    }
}

unsigned int ListSize(T_ListNode* list_) {
    if (NULL == list_) {
        return 0;
    }
    unsigned int listSize = 0;
    T_ListNode* node = list_;
    while (node) {
        listSize++;
        node = node ->next;
    }
    return listSize;
}

void PrintList(T_ListNode* list_) {
    printf("Printing list contents:\n");
    if (NULL == list_) {
        printf("List is empty\n");
        return;
    }
    T_ListNode* node = list_;
    unsigned int index = 0;
    while (node) {
        printf("List element #%u:\t%f\n", index, node->value);
        node = node ->next;
        index++;
    }
    return;
}