#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree *tree = createTree();
    insertValue(tree, 3);
    insertValue(tree, 1);
    insertValue(tree, 25);
    insertValue(tree, 14.22);
    insertValue(tree, 39.22);
    insertValue(tree, 15.27);
    insertValue(tree, 9);
    insertValue(tree, 23);
    insertValue(tree, 35.52);
    insertValue(tree, 43);

    //tree->root = Delete(tree->root, 25); //Проверка удаления

    printf("%d", nodesCount(tree->root));

    printTree(tree);

    destroyTree(tree);
    return 0;
}
