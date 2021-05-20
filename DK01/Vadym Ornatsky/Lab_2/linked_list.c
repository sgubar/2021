#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

T_ListNode* InitNode(void* data_, unsigned int dataLength_) {
    if ((NULL == data_) || (1 > dataLength_)) {
        return NULL;
    }
    T_ListNode* newNode = (T_ListNode*) malloc(sizeof(T_ListNode));
    if (NULL == newNode) {
        return NULL;
    }
    newNode->data = malloc(dataLength_);
    if (NULL == newNode->data) {
        free(newNode);
        return NULL;
    }
    memcpy(newNode->data, data_, dataLength_);
    newNode->dataLength = dataLength_;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

T_ListNode* InsertBefore(T_ListNode* node_, void* data_, unsigned int dataLength_) {
    if ((NULL == node_) || (NULL == data_) || (1 > dataLength_)) {
        return NULL;
    }
    T_ListNode* newNode = InitNode(data_, dataLength_);
    if (NULL == newNode) {
        return NULL;
    }
    newNode->previous = node_->previous;
    newNode->next = node_;
    node_->previous = newNode;
    if (NULL != newNode->previous) {
        newNode->previous->next = newNode;
    }
    return newNode;
}

T_ListNode* InsertAfter(T_ListNode* node_, void* data_, unsigned int dataLength_) {
    if ((NULL == node_) || (NULL == data_) || (1>dataLength_)) {
        return NULL;
    }
    T_ListNode* newNode = InitNode(data_, dataLength_);
    if (NULL == newNode) {
        return NULL;
    }
    newNode->previous = node_;
    newNode->next = node_->next;
    node_->next = newNode;
    return newNode;
}

void FreeList(T_ListNode* firstNode_) {
    if (NULL == firstNode_) {
        return;
    }
    T_ListNode* node = firstNode_;
    while (node) {
        if (node->data) free(node->data);
        T_ListNode* nodeToClear = node;
        node = node ->next;
        free(nodeToClear);
    }
}