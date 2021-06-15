#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef struct Node {
    float value;
    struct Node* next;
} Node;
void push(Node** head, int data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node** head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

Node* getNth(Node* head, float n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

Node* getLast(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void pushBack(Node* head, float value) {
    Node* last = getLast(head);
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}  


void insert(Node* head, unsigned n, float val) {
    unsigned i = 0;
    Node* tmp = NULL;
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*)malloc(sizeof(Node));
    tmp->value = val;
    if (head->next) {
        tmp->next = head->next;
    }
    else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

int deleteNth(Node** head, float n) {
    if (n == 0) {
        return pop(head);
    }
    else {
        Node* prev = getNth(*head, n - 1);
        Node* elm = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}



void CreateList(Node** head, float* arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while (i-- != 0);
}

void Print(const Node* head) {
    while (head) {
        printf("%lf\n", head->value );
        head = head->next;
    }
    printf("\n");
}
int getSize(const Node* head) {
    int i = 0;
    while (head) {
        i++;
        head = head->next;
    }
    return i;
}

void deleteList(Node** head) {
    while ((*head)->next) {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}
int main()
{
    float n; int ind;
    Node* head = NULL;
    float arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    CreateList(&head, arr, 10);

    Print(head);
    printf("Enter num to add it to list\n");
    scanf("%f",&n);
    pushBack(head, n);
    Print(head);
    printf("Enter index to add element\n");
    scanf("%d", &ind);
    printf("Enter num to add it by index\n");
    scanf("%f", &n);
    insert(head, ind,n);
    Print(head);
    printf("Enter index of num to delete it from list\n");
    scanf("%f", &n);
    deleteNth(&head, n);
    Print(head);
    printf("Size of list = %d \n", getSize(head));
    deleteList(&head);
    printf("List was deleted");
}
