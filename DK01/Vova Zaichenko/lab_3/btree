#include <stdio.h> 
#include <stdlib.h> 
 

typedef struct bTree_s { 
    int num; 
    struct bTree_s *left; 
    struct bTree_s *right; 
} bTree_t; 
 

bTree_t *createNode(int num) { 
    bTree_t *node = (bTree_t *)malloc(sizeof(bTree_t)); 
    if (node == NULL) { 
        printf("%s\n", "malloc error"); 
        exit(1); 
    } 
    node->num   = num; 
    node->left  = NULL; 
    node->right = NULL; 
    return node; 
} 
 

void insertNum(bTree_t **tree, int num) { 
    bTree_t *newNode = createNode(num); 
 
    bTree_t *head = *tree; 
    if (*tree == NULL) { 
        *tree = newNode; 
    } 
    else if (num < head->num) { 
        if (head->left == NULL) { 
            head->left = newNode; 
        } 
        else { 
            insertNum(&(head->left), num); 
        } 
    } 
    else if (num > head->num) { 
        if (head->right == NULL) { 
            head->right = newNode; 
        } 
        else { 
            insertNum(&(head->right), num); 
        } 
    } 
} 
 
 

void printBtree (bTree_t **tree) { 
    if (*tree !=NULL) {  
        printBtree(&((**tree).left));  
        printf("%d\n", (*tree)->num); 
        printBtree(&((**tree).right));  
    } 
} 
 

bTree_t *createTree(int *arr, int size) { 
    if (arr == NULL) {return NULL;} 
    bTree_t *res = NULL; 
    for (int i = 0; i < size; i++) { 
        if (res == NULL) {res = createNode(arr[i]);} 
        else {insertNum(&res, arr[i]);} 
    } 
    return res; 
} 
 

void deleteTree(bTree_t **tree) { 
    if (*tree != NULL) { 
        if ((*tree)->left != NULL) { 
            deleteTree(&(*tree)->left); 
        } 
        if ((*tree)->right != NULL) { 
            deleteTree(&(*tree)->right); 
        } 
        free(*tree); 
        *tree = NULL; 
    } 
} 
 
void deletElemWrapper(bTree_t **newTree, bTree_t *oldTree, int num) { 
    if (oldTree != NULL) { 
        if (oldTree->num != num) { 
            insertNum(newTree, oldTree->num); 
        } 
        deletElemWrapper(newTree, oldTree->left, num);  
        deletElemWrapper(newTree, oldTree->right, num);  
    } 
} 
 

void deleteElem(bTree_t **root, int num) { 
    bTree_t *newTree = NULL; 
    if (*root !=NULL) { 
        deletElemWrapper(&newTree, *root, num); 
        deleteTree(root); 
        *root = newTree; 
    } 
} 
 
int main() { 
    int size = 10; 
    int *arr = (int *)malloc(sizeof(int) * size); 
    for (int i = 0; i < size; i++) { 
        arr[i] = i*2; 
    } 
    bTree_t *t = createTree(arr, size); 
    deleteElem(&t, 12); 
    printBtree (&t); 
    deleteTree(&t); 
}
