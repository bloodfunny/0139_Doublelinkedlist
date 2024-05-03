#include <iostream>
using namespace std;

struct Node
{
	int noMhs;
	string name;
	Node *next;
	Node *prev;
};

Node *START = NULL;

void addNode()
{
	Node *newNode = new Node();
	cout << "\nEnter the roll number of the student: ";
	cin >> newNode->noMhs;
	cout << "\nEnter the name of the student: ";
	cin >> newNode->name;

	if (START == NULL || newNode->noMhs <= START->noMhs)
	{
		if (START != NULL && newNode->noMhs == START->noMhs)
		{
			cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
			return;
		}
		newNode->next = START;
		if (START != NULL)
		{
			START->prev = newNode;
		}
		newNode->prev = NULL;
		START = newNode;
	}
	else
	{
		Node *current = START;
		Node* previous = NULL;

		while (current != NULL && current->noMhs < newNode->noMhs)
		{
			previous = current;
			current = current->next;
		}
		newNode->next = current;
		newNode->prev = previous;

		if (current != NULL)
		{
			current->prev = newNode;
		}
		if (previous != NULL)
		{
			previous->next = newNode;
		}
		else
		{
			START = newNode;
		}
	}
}

bool search(int ro11no, Node** previous, Node** current)
{
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != ro11no)
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void deleteNode()
{
	Node* previous, * current;
	int ro11No;

	cout << "\nEnter ehe roll number of the student whose record is to be deleted: ";
	cin >> ro11No; 

	if (START == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	current = START;
	previous = NULL;

	while (current != NULL && current->noMhs != ro11No)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		cout << "\033{31mThe record with roll number" << ro11No << "not found\033{0m" << endl;
		return;
	}

	if (current == START)
	{
		START = START->next;
		if (START != NULL)
		{
			START->prev = NULL;
		}
	}
	else
	{
		previous->next = current->next;
		if (current->prev != NULL)
		{
			current->next->prev = previous;
		}
	}

	delete current;
	cout << "\x1b{32mRecord with ro11 number " << ro11No << " delete\x1b[0m" << endl;

}
 
bool listEmpty()
{
	return (START == NULL);
}

void traverse()
{
	if (listEmpty())
		cout << "\nList is empty " << endl;
	else
	{
		cout << "\nRecords in ascending orderof roll number ara:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL)
		{
			cout << currentNode->noMhs << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void revtraverse()
{
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else
	{
		cout << "\nRecords in ascending order of ro11 number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode - currentNode->next;
		while (currentNode != NULL)
		{
			cout << currentNode->noMhs << "" << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void searchData()
{

}