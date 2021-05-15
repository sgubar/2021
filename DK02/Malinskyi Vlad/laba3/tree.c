#include <stdlib.h>
#include "tree.h"

Tree *createTree() //Init Empty Tree
{
    Tree *createdTree = (Tree *) malloc(sizeof(Tree));
    if(NULL != createdTree)
    {
        createdTree->root = NULL;
    }
    return createdTree;
}

void destroyNode(Node *root)
{
    if(root != NULL)
    {
        destroyNode(root->leftChild);
        destroyNode(root->rightChild);

        free(root);
    }
}

void destroyTree(Tree *treeRoot)
{
    if(NULL != treeRoot)
    {
        destroyNode(treeRoot->root);
        free(treeRoot);
    }
}

Node *createNode(double nValue) //returns a pointer to created node with nValue
{
    Node *result = (Node *) malloc(sizeof(double));

    if(NULL != result)
    {
        result->leftChild = NULL;
        result->rightChild = NULL;
        result->value = nValue;
    }
    return result;
}

void insertValue(Tree *tree, double nValue)
{
    if(NULL == tree)
    {
        return;
    }

    Node *node = createNode(nValue);
    if(NULL == node)
    {
        return;
    }
    if(NULL == tree->root)
    {
        tree->root = node;
    }
    else
    {
        Node *current = tree->root;
        Node *parent = NULL;

        while(1)
        {
            parent = current;

            if(nValue < current->value)
            {
                current = current->leftChild;
                if(NULL == current)
                {
                    parent->leftChild = node;
                    break;
                }
            }
            else if(nValue > current->value)
            {
                current = current->rightChild;
                if(NULL == current)
                {
                    parent->rightChild = node;
                    break;
                }
            }
        }
    }
}

Node *findNodeByValue(Tree *tree, double nValue) //Returns NULL if node with nValue doesn't exist
{
    Node *currentNode = NULL;

    if(NULL != tree && NULL != tree->root)
    {
        Node *tmp = tree->root;
        while(tmp != NULL)
        {
            if(nValue < tmp->value)
            {
                tmp = tmp->leftChild;
            }
            else if (nValue > tmp->value)
            {
                tmp = tmp->rightChild;
            }
            else if(tmp->value == nValue)
            {
                return tmp;
            }
        }
    }
    return currentNode;
}
//////
Node* Delete(Node *root, double data)
{
    if(NULL == root) return NULL;
    else if (data < root->value) root->leftChild = Delete(root->leftChild, data);
    else if (data > root->value) root->rightChild= Delete(root->rightChild, data);
    else // Element to be deleted found
    {
        //No child
        if(root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            root = NULL;
        }
        // One child
        else if (root->leftChild == NULL) {
            Node *temp = root;
            root = root->rightChild;
            free(temp);
        }
        else if (root->rightChild == NULL) {
            Node *temp = root;
            root = root->leftChild;
            free(temp);
        }
        else {
            Node *temp = getSuccessor(root->rightChild);
            root->value = temp->value;
            root->rightChild = Delete(root->rightChild, temp->value);
        }
    }

    return root;
}
////

Node* getSuccessor(Node* current) //Returns a pointer to minimal node bigger than current
{
    while (current->leftChild != NULL) {
        current = current->leftChild;
    }
    return current;
}

void printTabs(int numSpaces)
{
    for(int i = 0; i < numSpaces; ++i)
        printf("  ");
}
int nodesCount(Node *root)
{
    if(root == NULL) return 0;
    return(1+nodesCount(root->rightChild) + nodesCount(root->leftChild));
}
void printTree_rec(Node* root, int level)
{
    if(NULL == root)
    {
        printTabs(level);
        printf("---<empty>---\n");
        return;
    }
    printTabs(level);
    printf("left\n");
    printTree_rec(root->leftChild, level+1);

    printTabs(level);
    printf("value = %.2lf\n", root->value);

    printTabs(level);
    printf("right\n");
    printTree_rec(root->rightChild, level+1);
}

void printTree(Tree *tree) //Print tree with vertical hirearchy
{
    printTree_rec(tree->root, 0);
}
