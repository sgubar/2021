#ifndef ABO.h
#define ABO.h

typedef struct tree{
                   float value;
                   struct tree *left;
                   struct tree *right;
                   struct tree *parent;
                   } node;

node *create(node *root, float value);
node *add(node *root, float value);
node *search(node * root, float value);
node *min(node *root);
node *succ(node *root);
node *delete(node *root, float value);
void inorder(node* root);
void freemem(node* root);

#endif
