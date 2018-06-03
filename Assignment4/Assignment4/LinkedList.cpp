#include "LinkedList.h"

/*
No items being added to the list
*/
template<class T1>
LinkedList<T1>::LinkedList()
{
}

/*
For adding a single element upon creation
*/
template<class T1>
LinkedList<T1>::LinkedList(T1 item)
	: head{ new Node{ std::move(item) } }
	, back{ head }
	, currentSize{ 1 }
{
}

/*
Deleting all nodes through clear()
*/
template<class T1>
LinkedList<T1>::~LinkedList()
{
	clear();
}

/*
Adding an item to the back of the list
*/
template<class T1>
void LinkedList<T1>::add(T1 item)
{
	Node* temp = new Node{ std::move(item) };
	if (back == nullptr)
	{
		back = temp;
		head = temp;
	}
	else
	{
		//if (head->next == nullptr)
		//	head->next = temp;
		back->next = temp;
		back = back->next;
	}
	currentSize++;
}

/*
Takes out the item at the specified index
*/
template<class T1>
T1 LinkedList<T1>::remove(int index)
{
	if (index < 0 || index >= currentSize) { //For invalid indexes
		throw new std::out_of_range("invalid index");
	}

	Node* toRemove;
	if (index == 0) { //removing a head node
		toRemove = head;
		head = head->next;
		if (head == nullptr) {
			back = nullptr;
		}
	}
	else {
		Node* temp = head;
		for (int i = 0; i < index - 1; i++) {//move until node to delete
			temp = temp->next;
		}
		toRemove = temp->next; 
		temp->next = toRemove->next;
		if (back == toRemove) {
			back = temp;
		}
	}

	T1 ret = toRemove->item;
	delete toRemove;
	currentSize--;
	return ret;//returns the deleted node item
}

/*
Deleting a whole list. Keeps track of the before
and the after node so that it hits every node
*/
template<class T1>
void LinkedList<T1>::clear()
{
	if (currentSize == 0) { 
		return;
	}
	Node* toDelete = head; 
	Node* nextDelete = head->next;
	while (nextDelete != nullptr) {
		delete toDelete;
		toDelete = nextDelete;
		nextDelete = nextDelete->next;
	}
	delete toDelete;
	currentSize = 0;
	head = nullptr;
	back = nullptr;
}

template<class T1>
int LinkedList<T1>::size() const
{
	return currentSize;
}

/*
Goes through each item one by one until it
finds the item or gets to the end of the list
returns the index of the given item
*/
template<class T1>
int LinkedList<T1>::contains(T1 item) const
{
	Node* temp = head;
	int ret = 0;
	while (temp != nullptr) {
		if (temp->item == item) {
			return ret;
		}
		temp = temp->next;
		ret++;
	}
	return -1;
}

/*
Returns the item at the specified index
returns a reference to the item
*/
template<class T1>
T1 LinkedList<T1>::getItem(int index) const
{
	if (index < 0 || index >= currentSize) {
		throw new std::out_of_range("invalid index");
	}
	Node* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	T1 ret = temp->item;
	return ret;
}

/*
Goes through each item and preforms the visit function
on each item.
*/
template<class T1>
void LinkedList<T1>::traverse(void visit(T1 item)) const
{
	Node* temp = head;
	while (temp != nullptr) {
		visit(temp->item);
		temp = temp->next;
	}
}

