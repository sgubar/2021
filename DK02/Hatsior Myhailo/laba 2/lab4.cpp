#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	Node* next;
	char data;
};
Node* head = nullptr;

void pushfront(char data)
{
	if (head == nullptr)
	{
		head = new Node;
		head->data = data;
		head->next = nullptr;
	}
	else
	{
		Node* temp = new Node;
		temp->data = data;
		temp->next = head;
		head = temp;
	}
}

void print()
{
	Node* temp = head;
	while (temp)
	{
		cout << temp->data;
		temp = temp->next;
	}
}

void clear()
{
	Node* temp = head;
	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
}

int main()
{
	string filename;
	cout << "Enter name of file as name.txt: " << endl; cin >> filename;
	ifstream in(filename);
	if (in.is_open())
	{
		char symbol;
		while (!in.eof())
		{
			symbol = in.get();
			pushfront(symbol);
		}
	}
	else
	{
		cout << "Can't open file!" << endl;
	}
	print();
	clear();
	return 0;
}