#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

static int IsLeaf(T_Node* node_) {
    return ((NULL == node_->left) && (NULL == node_->right)) ? 1 : 0;
}

static T_Node* InitNode(char value_) {
    T_Node* newNode = (T_Node*) malloc(sizeof(T_Node));
    if (NULL == newNode) {
        return NULL;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value_;
    return newNode;
}

static void DestroyNode(T_Node *node_)
{
	if (NULL != node_)
	{
		DestroyNode(node_->left);
		DestroyNode(node_->right);
	
		free(node_);
	}
}

static T_Node* FindMaxNodeInBranch(T_Node* startNode_) {
    T_Node* node = startNode_;
    while (node->right) {
        node = node->right;
    }
    return node;
}

static void PrintNode(T_Node* node) {
	if (NULL == node) {
		return;
	}
    PrintNode(node->left);
    printf("%d ", node->value);
    PrintNode(node->right);
}

T_Tree* CreateTree() {
    T_Tree* newTree = (T_Tree*) malloc(sizeof(T_Tree));
    if (NULL == newTree) {
        return NULL;
    }
    newTree->count = 0;
    newTree->root = NULL;

    return newTree;
}

void DestroyTree(T_Tree* tree_) {
    if (NULL == tree_) {
        return;
    }
    DestroyNode(tree_->root);
    return;
}

void PrintTree(T_Tree* tree_) {
    if ((NULL == tree_) || (NULL == tree_->root)) {
        printf("Tree is empty\n");
		return;
    }
    PrintNode(tree_->root);
}

T_Node* InsertNode(T_Tree* tree_, char value_) {
    if (NULL == tree_) {
        return NULL;
    }
    
    T_Node* newNode = InitNode(value_);

    if (NULL == newNode) {
        return NULL;
    }

    if (NULL == tree_->root) {
        tree_->root = newNode;
        printf("Tree root initialized with value: %d\n", value_);
        return tree_->root;
    }
    T_Node* traverseNode = tree_->root;
    T_Node* parentNode = tree_->root;
    
    while (traverseNode) {
        parentNode = traverseNode;
        if (value_ > traverseNode->value) {
            traverseNode = traverseNode->right;
            if (NULL == traverseNode) {
                parentNode->right = newNode;
                printf("Inserted node with value: %d at right from %d\n", value_, parentNode->value);
                break;
            }
        } else if ((value_ < traverseNode->value)) {
            traverseNode = traverseNode->left;
            if (NULL == traverseNode) {
                parentNode->left = newNode;
                printf("Inserted node with value: %d at left from %d\n", value_, parentNode->value);
                break;
            }
        } else {
            printf("Found duplicated node with value: %d\n", value_);
            return traverseNode;
        }

    }
    tree_->count++;

    return newNode;
}

void DeleteNode(T_Tree* tree_, char value_) {
	if (NULL == tree_) {
		return;
	}
	if (NULL == tree_->root) {
		return;
	}

	T_Node* traversalNode = tree_->root;
	T_Node* parent = tree_->root;

	// find node for delete
	while (value_ != traversalNode->value) {
		parent = traversalNode;
		if (value_ < traversalNode->value) {
			traversalNode = traversalNode->left;
		}
		else {
			traversalNode = traversalNode->right;
		}

		if (NULL == traversalNode) {
			printf("Node for deletion with value: %d - not found.\n", value_);
			return;
		}
	}

	if (IsLeaf(traversalNode)) {
		if (tree_->root == traversalNode) {
			tree_->root = NULL;
		}
		else if (parent->left == traversalNode) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
		DestroyNode(traversalNode);
	}
	else if (NULL == traversalNode->right) {
		if (tree_->root == traversalNode) {
			tree_->root = traversalNode->left;
		}
		else if (parent->left == traversalNode) {
			parent->left = traversalNode->left;
		}
		else {
			parent->right = traversalNode->right;
		}
		DestroyNode(traversalNode);
	}
	else if (NULL == traversalNode->left) {
		if (tree_->root == traversalNode) {
			tree_->root = traversalNode->right;
		}
		else if (parent->right == traversalNode) {
			parent->right = traversalNode->right;
		}
		else {
			parent->left = traversalNode->left;
		}
		DestroyNode(traversalNode);
	}
	else {
		T_Node* replacement = FindMaxNodeInBranch(traversalNode->left);
		char replacementValue = replacement->value;
		DeleteNode(tree_, replacement->value);
		traversalNode->value = replacementValue;
	}
	tree_->count--;
    return;
}

T_Node* FindNode(T_Tree* tree_, char value_) {
    if (NULL == tree_) {
        return NULL;
    }
    if (NULL == tree_->root) {
        return NULL;
    }

    T_Node* node = tree_->root;
    while (node->value != value_) {
        if (node->value > value_) {
            node = node->left;
        } else {
            node = node->right;
        }
        if (NULL == node) {
            printf("Node with value %d - not found.\n", value_);
            return NULL; 
        }
    }

    return node;

}