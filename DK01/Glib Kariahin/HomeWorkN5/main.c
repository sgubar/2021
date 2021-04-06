
#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {

    DoubleTree *tree = createDoubleTree();
    //Створюємо дерево типу double.

    insertDoubleValueToTree(tree, 53.0);
    insertDoubleValueToTree(tree, 0);
    insertDoubleValueToTree(tree, 14);
    insertDoubleValueToTree(tree, 9);
    insertDoubleValueToTree(tree, -890.8);
    insertDoubleValueToTree(tree, -34523);
    insertDoubleValueToTree(tree, 345);
    insertDoubleValueToTree(tree, -0.345234);
    //Додаємо елементи до дерева.
    printTree(tree);
    //Друкуємо дерево.
    deleteNodeWithValue(tree, 0);
    //Видаляємо елемент з дерева.
    printTree(tree);
    //Знову друкуємо дерево.

    destroyDoubleTree(tree);
    //Видаляємо дерево.


    return 0;
}
