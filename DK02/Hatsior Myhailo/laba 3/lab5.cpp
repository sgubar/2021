#include <iostream>
using namespace std;

struct TreeNode
{
	TreeNode* Left = NULL;
	TreeNode* Right = NULL;
	int data;
};

TreeNode* root = NULL;

void createTree(int data, TreeNode* current)
{
	root = current;
}

void push(int data)
{
	TreeNode* current = new TreeNode;
	current->data = data;
	if(root)
	{
		TreeNode* tmp = root;
		while (tmp)
		{
			if (tmp->data > data)
			{
				if (!tmp->Left)
				{
					tmp->Left = current;
					return;
				}
				tmp = tmp->Left;
			}
			else if (tmp->data < data)
			{
				if (!tmp->Right)
				{
					tmp->Right = current;
					return;
				}
				tmp = tmp->Right;
			}
		}
	}
	else
	{
		createTree(data, current);
	}
}

void inOrderTravers(TreeNode* root) {
	if (root) {
		inOrderTravers(root->Left);
		printf("%d ", root->data);
		inOrderTravers(root->Right);
	}
}

void search(TreeNode* root, int data)
{
	if (root)
	{
		if (root->data > data)
			search(root->Left, data);
		else if (root->data < data)
			search(root->Right, data);
		else if (root->data == data)
			printf("%d ", data); return;
	}
}


void FreeTree(TreeNode* root) {
	if (!root) { return; }
	if (root->Left)   
		FreeTree(root->Left);
	if (root->Right)  
		FreeTree(root->Right);
	delete root;
}

TreeNode* minValueNode(TreeNode* node)
{
	TreeNode* current = node;
	while (current && current->Left != NULL)
		current = current->Left;

	return current;
}

TreeNode* deleteNode(TreeNode* root, int data)
{
	if (root == NULL)
		return root;

	if (data < root->data)
		root->Left = deleteNode(root->Left, data);

	else if (data > root->data)
		root->Right = deleteNode(root->Right, data);

	else 
	{
		if (root->Left == NULL and root->Right == NULL)
		{
			return NULL;
		}
		else if(root->Left == NULL)
		{
			TreeNode* temp = root->Right;
			free(root);
			return temp;
		}
		else if (root->Right == NULL) 
		{
			TreeNode* temp = root->Left;
			free(root);
			return temp;
		}

		TreeNode* temp = minValueNode(root->Right);

		root->data = temp->data;

		root->Right = deleteNode(root->Right, temp->data);
	}
	return root;
}

int main()
{
	int menuitem = 6, number;
	cout << endl;
	cout << "~~~~~~~~~~~>>Menu<<~~~~~~~~~~~" << endl;
	cout << "1. Insert element to tree" << endl;
	cout << "2. Delete element from tree" << endl;
	cout << "3. Display tree" << endl;
	cout << "4. Delete tree" << endl;
	cout << "5. search element in tree" << endl;
	cout << "6. exit" << endl;

	while (menuitem != 0)
	{
		while (true)
		{
			cout << "Enter menu item : " << endl; cin >> menuitem;
			if (!cin)
			{
				cout << "entered data is not correct, try again!" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else if (menuitem < 0 || menuitem > 5)
			{
				cout << "menu item with this number does not exist, please try again!" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else { break; }
		}

		if (menuitem == 1)
		{
			while (true)
			{
				cout << "Enter element : " << endl; cin >> number;
				if (!cin)
				{
					cout << "entered data is not correct, try again!" << endl;
					cin.clear();
					while (cin.get() != '\n');
				}
				else break;
			}
			push(number);

		}
		if (menuitem == 2)
		{
			while (true)
			{
				cout << "Enter element : " << endl; cin >> number;
				if (!cin)
				{
					cout << "entered data is not correct, try again!" << endl;
					cin.clear();
					while (cin.get() != '\n');
				}
				else break;
			}
			deleteNode(root, number);

		}
		if (menuitem == 3)
		{
			cout << "Tree: " << endl;
			inOrderTravers(root);
			cout << endl;
		}
		if (menuitem == 4)
		{
			FreeTree(root);
		}
		if (menuitem == 5)
		{
			while (true)
			{
				cout << "Enter element : " << endl; cin >> number;
				if (!cin)
				{
					cout << "entered data is not correct, try again!" << endl;
					cin.clear();
					while (cin.get() != '\n');
				}
				else break;
			}
			search(root, number);
		}
		if (menuitem == 0)
		{
			return 0;
		}
	}
}
