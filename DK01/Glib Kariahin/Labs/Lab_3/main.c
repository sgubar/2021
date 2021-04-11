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

    //Намагаємося віднайти видалений елемент.
    if(NULL==findNodeWithValue(tree,0)){
        printf("Element ""zero"" NOT FOUND");
    }else{
        printf("Element ""zero"" FOUND");
    }
    printf("\n");
    //Рахуємо кількість елементів
    printf("Elements :%d", countNodesWithTree(tree));
    destroyDoubleTree(tree);
    //Видаляємо дерево.


    return 0;
}
