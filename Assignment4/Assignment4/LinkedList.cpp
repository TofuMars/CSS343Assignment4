#include "LinkedList.h"


template<class T1>
LinkedList<T1>::LinkedList() {
	head = nullptr;
	back = nullptr;
	currentSize = 0;
}

template<class T1>
LinkedList<T1>::LinkedList(T1 item)
{
	Node* temp = new Node(item);
	head = temp;
	back = temp;
	currentSize = 1;
}


template<class T1>
LinkedList<T1>::~LinkedList()
{
	clear();
	currentSize = 0;
}

template<class T1>
void LinkedList<T1>::add(T1 item)
{
	Node* temp = new Node(item);
	if(back == nullptr)
	{
		back = temp;
		head = temp;
	}
	else
	{
		back->next = temp;
		back = back->next;
	}
	currentSize++;
}

template<class T1>
T1 LinkedList<T1>::remove(int index)
{
	if (currentSize == 0) {
		return nullptr;
	}
	if (index == 0) {
		Node* temp = head;
		head = head->next;
		T1 ret = temp->item;
		delete temp;
		currentSize--;
		return ret;
	}
	else {
		Node* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		Node* toRemove = temp->next;
		temp->next = toRemove->next;
		T1 ret = toRemove->item;
		delete toRemove;
		currentSize--;
		return ret;
	}

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
}

template<class T1>
int LinkedList<T1>::size()
{
	return currentSize;
}

template<class T1>
int LinkedList<T1>::contains(T1 item)
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
T1 LinkedList<T1>::getItem(int index)
{
	if (index < 0 || index >= currentSize) {
		return nullptr;
	}
	Node* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	T1 ret = temp->item;
	return ret;
}

template<class T1>
void LinkedList<T1>::traverse(void visit(T1 item))
{
	Node* temp = head;
	while (temp != nullptr) {
		visit(temp->item);
		temp = temp->next;
	}
}

