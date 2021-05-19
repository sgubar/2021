#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct ListNode {
    void* data;
    unsigned int dataLength;
    struct ListNode* previous;
    struct ListNode* next;
} T_ListNode;


T_ListNode* InitNode(void* data_, unsigned int dataLength_);
T_ListNode* InsertBefore(T_ListNode* node_, void* data_, unsigned int dataLength_);
T_ListNode* InsertAfter(T_ListNode* node_, void* data_, unsigned int dataLength_);
void FreeList(T_ListNode* firstNode_);
#endif