#include "linklist.h"



bool LinkList::insert(string word)
{
	node *temp = headptr;
	node *prev = nullptr; 
	node *new_node = nullptr;

	new_node = new(nothrow) node; // new nod that will go into the list
	if (new_node == nullptr)
	{
		return false;
	}

	new_node->word = word;
	new_node->frequencyCount = 1;
	new_node->next = nullptr;

	if (headptr == nullptr)
	{
		headptr = new_node;
		return true;
	}
	if (new_node->word <= headptr->word)
	{
		new_node->next = headptr;
		headptr = new_node;
		return true;
	}
	while (temp != nullptr && temp->word <= new_node->word )
	{
		prev = temp;
		temp = temp->next; 
	}
	new_node->next = temp;
	prev->next = new_node;
	return true;
}

bool LinkList::isEmpty()
{
	if (headptr == nullptr)
		return true;
	return false;
}