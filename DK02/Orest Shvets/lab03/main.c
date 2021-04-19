// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Tree.h"
#include <stdio.h>
int main(int argc, const char* argv[])
{
	IntTree* the_tree = createIntTree();
	insertIntValueToTree(the_tree, 75);
	insertIntValueToTree(the_tree, 46);
	insertIntValueToTree(the_tree, 32);
	insertIntValueToTree(the_tree, 15);
	insertIntValueToTree(the_tree, 37);
	insertIntValueToTree(the_tree, 46);
	insertIntValueToTree(the_tree, 31);
	insertIntValueToTree(the_tree, 48);
	findNode(the_tree, 46);
	printIntTree(the_tree);
	deleteNodeWithValue(the_tree, 31);
	deleteNodeWithValue(the_tree, 48);
	printIntTree(the_tree);
	destroyIntTree(the_tree);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
