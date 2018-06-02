#include "LinkedList.h"


template<class T1>
LinkedList<T1>::LinkedList()
{
}

template<class T1>
LinkedList<T1>::LinkedList(T1 item)
	: head{ new Node{ std::move(item) } }
	, back{ head }
	, currentSize{ 1 }
{
}

template<class T1>
LinkedList<T1>::~LinkedList()
{
	clear();
}

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

template<class T1>
T1 LinkedList<T1>::remove(int index)
{
	if (index < 0 || index >= currentSize) {
		throw new std::out_of_range("invalid index");
	}

	Node* toRemove;
	if (index == 0) {
		toRemove = head;
		head = head->next;
		if (head == nullptr) {
			back = nullptr;
		}
	}
	else {
		Node* temp = head;
		for (int i = 0; i < index - 1; i++) {
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
	return ret;
}

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

template<class T1>
void LinkedList<T1>::traverse(void visit(T1 item)) const
{
	Node* temp = head;
	while (temp != nullptr) {
		visit(temp->item);
		temp = temp->next;
	}
}

