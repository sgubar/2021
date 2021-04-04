#include "M3.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

node *create(node *root, float value){
    node *tmp = malloc(sizeof(node));
    tmp -> value = value;
    tmp -> parent = NULL;
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}

node *add(node *root, float value){
    node *root2 = root, *root3 = NULL;
    node *tmp = malloc(sizeof(node));
    tmp -> value = value;
    while (root2 != NULL){
        root3 = root2;
        if (value < root2 -> value)
            root2 = root2 -> left;
        else
            root2 = root2 -> right;
    }
    tmp -> parent = root3;
    tmp -> left = NULL;
    tmp -> right = NULL;
    if (value < root3 -> value) root3 -> left = tmp;
    else root3 -> right = tmp;
    return root;
}

node *search(node * root, float value){
    if ((root == NULL) || (root -> value = value))
        return root;
    if (value < root -> value)
        return search(root -> left, value);
    else return search(root -> right, value);
}

node *min(node *root){
    node *l = root;
    while (l -> left != NULL)
        l = l -> left;
    return l;
}

node *delete(node *root, float value){
	if (root == NULL)
		return root;
	
	if (value < root->value){
		root->left = delete(root->left, value);
	}else if (value > root->value){
		root->right = delete(root->right, value);
	}else if(root->left != NULL && root->right != NULL){
		root->value = min(root->right)->value;
		root->right = delete(root->right, root->value);
	}else if(root->left!=NULL){
		root = root->left;
	}else if(root->right!=NULL){
		root = root->right;
	}else root = NULL;
	
	return root;
}

void inorder(node *root){
    if (root == NULL)
        return;
    inorder(root -> left);
    if (root -> value)
        printf("%0.2f ", root -> value);
    inorder(root -> right);
}

void freemem(node* root){
	if (root != NULL) {
		freemem(root->left);
		freemem(root->right);
		free(root);
	}
}
