#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct ListNode {
    double value;
    struct ListNode* next;
} T_ListNode;


T_ListNode* InitNode(double value_);
T_ListNode* CreateList(double value_); // Create list with one element with value_
T_ListNode* AddToList(T_ListNode* list_, double value_);
T_ListNode* RemoveFromListByIndex(T_ListNode* list_, unsigned int index_);
T_ListNode* InsertByIndex(T_ListNode* list_, unsigned int index_, double value_);
void DestroyList(T_ListNode* list_);
unsigned int ListSize(T_ListNode* list_);
void PrintList(T_ListNode* list_);
#endif