#include <stdio.h>
#include "tree.h"

int main(int argc, const char* argv[]) {

    BinaryTree* tree = createTree();
    int result;

    unsigned numberOfValues = 0;
    printf("How many values do you want to insert? Number: ");
    result = scanf_s("%u", &numberOfValues);
    if (!result) {
        return 1;
    }

    while (numberOfValues--) {
        int value;
        printf("Enter value (from -32,768 to 32,767): ");
        result = scanf_s("%i", &value);
        if (result == 1) {
            insert(tree, value);
        }
    }

    print(tree);

    int valueToFind;
    printf("What value do you want to find?\nEnter value (from -32,768 to 32,767): ");
    result = scanf_s("%i", &valueToFind);
    if (!result) {
        return 1;
    }

    Node* foundedNode = find(tree, valueToFind);
    if (foundedNode != NULL) {
        printf("This values is in tree on address: %p\n", foundedNode);
    }
    else {
        printf("No such element in tree\n");
    }

    int valueToDelete;
    printf("What value do you want to delete?\nEnter value (from -32,768 to 32,767): ");
    result = scanf_s("%i", &valueToDelete);
    if (!result) {
        return 1;
    }

    delete(tree, valueToDelete);
    print(tree);

    destroyTree(tree);
    print(tree);

    return 0;
}
