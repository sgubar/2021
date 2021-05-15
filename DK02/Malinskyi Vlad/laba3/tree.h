#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

typedef struct  __tagNode{
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
    double value;
} Node;

typedef struct __tagTree {
    Node *root;
} Tree;

int nodesCount(Node *root);

//Function Declarations
Tree *createTree();
void destroyTree(Tree *treeRoot);

Node *Delete(Node *root, double data);

Node *createNode(double nValue);
void destroyNode(Node *nodeToDestroy); //Destroys node and recursively all it's childs

void insertValue(Tree *tree, double nValue);

Node *findNodeByValue(Tree *tree, double nValue);
Node* getSuccessor(Node* current);

//Output
void printTabs(int numSpaces);
void printTree_rec(Node* root, int level);
void printTree(Tree *tree);

#endif // TREE_H_INCLUDED
