

#include "tree.h"
#include <stdlib.h>

static void destroyNode(DoubleNode *aNode);
static DoubleNode *createDoubleNodeWithValue(double aValue);
static DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete);
static void print_double_node(DoubleNode *node);

DoubleTree *createDoubleTree()
{
    DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));

    if (NULL != theTree)
    {
        theTree->root = NULL;
        theTree->count = 0;
    }

    return theTree;
}

void destroyDoubleTree(DoubleTree *aTree)
{
    if (NULL != aTree)
    {
        destroyNode(aTree->root);

        free(aTree);
    }
}

void insertDoubleValueToTree(DoubleTree *aTree, double aValue)
{
    if (NULL == aTree)
    {
        return;
    }

    DoubleNode *theNode = createDoubleNodeWithValue(aValue);
    if (NULL == theNode)
    {
        return;
    }

    if (NULL == aTree->root)
    {
        aTree->root = theNode;
        aTree->count ++;
    }
    else
    {
        DoubleNode *theCurrent = aTree->root;
        DoubleNode *theParent = NULL;

        while (1)
        {
            theParent = theCurrent;

            if (aValue < theCurrent->value)
            {
                theCurrent = theCurrent->leftChild;
                if (NULL == theCurrent)
                {
                    theParent->leftChild = theNode;
                    break;
                }
            }
            else
            {
                theCurrent = theCurrent->rightChild;
                if (NULL == theCurrent)
                {
                    theParent->rightChild = theNode;
                    break;
                }
            }
        }

        aTree->count ++;
    }
}



void deleteNodeWithValue(DoubleTree *aTree, double aValue) {

    // check input parameters
    if (NULL == aTree || NULL == aTree->root) {
        return ;
    }



    DoubleNode *current = aTree->root;
    DoubleNode *parent = aTree->root;


    while (aValue != current->value) {
        parent = current;
        if (aValue < current->value) {
            current = current->leftChild;
            aTree->count--;
        } else {
            current = current->rightChild;
            aTree->count--;
        }

        if (NULL == current) {
            return ;
        }
    }



    if (NULL == current->leftChild && NULL == current->rightChild) {
        if (aTree->root == current) {
            aTree->root = NULL;
        } else if (parent->leftChild == current) {
            parent->leftChild = NULL;
        } else {
            parent->rightChild = NULL;
        }

        aTree->count --;
    } else if (NULL == current->rightChild) {
        if (aTree->root == current) {
            aTree->root = current->leftChild;
        } else if (parent->leftChild == current) {
            parent->leftChild = current->leftChild;
        } else {
            parent->rightChild = current->rightChild;
        }
    } else if (NULL == current->leftChild) {
        if (aTree->root == current) {
            aTree->root = current->rightChild;
        } else if (parent->rightChild == current) {
            parent->rightChild = current->rightChild;
        } else {
            parent->leftChild = current->leftChild;
        }
    } else {
        DoubleNode *successor = getSuccessor(aTree, current);
        if (aTree->root == successor) {
            aTree->root = NULL;
        } else if (parent->leftChild == current) {
            parent->leftChild = successor;
        } else {
            parent->rightChild = successor;
        }
        current->leftChild = NULL;
        current->rightChild = NULL;
    }

    destroyNode(current);
}

//void mergeTrees(ShortTree *aTreeDst, ShortTree *aTreeSrc);
//
void printTree(DoubleTree *aTree) {
    DoubleNode* item = aTree->root;
    print_double_node(item);
}

void print_double_node(DoubleNode *node) {
    if (node == NULL)
        return;
    print_double_node(node->leftChild);
    printf("Element: %f\n", node->value);
    print_double_node(node->rightChild);
}
int countNodesWithTree(DoubleTree *aTree){
    return aTree->count;
}

#pragma mark -
void destroyNode(DoubleNode *aNode)
{
    if (NULL != aNode)
    {
        destroyNode(aNode->leftChild);
        destroyNode(aNode->rightChild);

        free(aNode);
    }
}

DoubleNode *createDoubleNodeWithValue(double aValue)
{
    DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));

    if (NULL != theNode)
    {
        theNode->leftChild = NULL;
        theNode->rightChild = NULL;
        theNode->value = aValue;
    }

    return theNode;
}

DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete) {
    DoubleNode *successParent = toDelete;
    DoubleNode *successor = toDelete;
    DoubleNode *current = toDelete->rightChild;

    while(NULL != current) {
        successParent = successor;
        successor = current;
        current = current->leftChild;
    }
//current = NULL;
//successor = 35
    if (successor != toDelete->rightChild) { // 35 != 39
        successParent->leftChild = successor->rightChild; //39 -> NULL
        successor->rightChild = toDelete->rightChild; //35->39
    }

    successor->leftChild = toDelete->leftChild;

    return successor;
}
DoubleNode *findNodeWithValue(DoubleTree *tree, double aValue){

    DoubleNode *current = tree->root;
    while (aValue != current->value) {

        if (aValue < current->value) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }

        if (NULL == current) {
            return NULL;
        }

    }
    return current;
}
