#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
	DoubleTree *tree = createDoubleTree();
  insertDoubleValueToTree(tree, 59.5);

  int n = 6;
  for(int i = 0; i < n; i++) {
    insertDoubleValueToTree(tree, rand()%100);
  }

  insertDoubleValueToTree(tree, 70.85);
  printTree(tree->root);
  printf("\n");

  findNodeWithValue(tree, 59.5);
  deleteNodeWithValue(tree, 70.85);

  printTree(tree->root);
  printf("\n");
  
  destroyDoubleTree(tree);
}
