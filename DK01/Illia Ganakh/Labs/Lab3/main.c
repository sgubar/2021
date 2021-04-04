#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
	IntTree *tree = createIntTree();
  insertIntValueToTree(tree, 59);
  int n = 6;
  for(int i = 0; i < n; i++) {
    insertIntValueToTree(tree, rand()%100);
  }

  insertIntValueToTree(tree, 70);
  printTree(tree->root);
  printf("\n");
  findNodeWithValue(tree, 59);
  deleteNodeWithValue(tree, 70);
  printTree(tree->root);
  printf("\n");
  destroyIntTree(tree);
}
