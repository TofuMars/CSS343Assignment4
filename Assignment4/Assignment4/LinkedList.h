#ifndef LL_LIST
#define LL_LIST
#include "HashEntry.h"

/*
LinkedList is an array-like structure that creates nodes which hold the data
of the current Item and the location of the next Node.
*/
template<class T1>
class LinkedList {
	/*
	Node structure to hold the item and the next location
	*/
	struct Node {
		Node* next{ nullptr };
		T1 item;
		Node(T1 in) : item{ std::move(in) } {}
	};

private:
	/*
	Holds the first element's data
	*/
	Node* head{ nullptr };

	/*
	O(1) for add()
	*/
	Node* back{ nullptr };

	/*
	O(1) for finding the size
	*/
	int currentSize{ 0 };
public:

	/*
	Creates an empty LinkedList
	*/
	LinkedList<T1>();

	/*
	Creates a new LinkedList with item as the first item
	*/
	LinkedList<T1>(T1 item);

	/*
	Deletes this object
	*/
	~LinkedList<T1>();

	/*
	Adds the item to the end of the LinkedList O(n)
	*/
	void add(T1 item);

	/*
	Removes and returns the item at index
	*/
	T1 remove(int index);

	/*
	Removes all items
	*/
	void clear();

	/*
	Returns the size of the LinkedList
	*/
	int size() const;

	/*
	Checks whether item is found within the LinkedList,
	if so, returns the index, returns -1 otherwise
	*/
	int contains(T1 item) const;

	/*
	Returns the item at the given index. If index is too
	big, returns nullptr. If index is negative, returns nullptr
	*/
	T1 getItem(int index) const;

	/*
	Preforms the visit fuction on all items within the list
	*/
	void traverse(void visit(T1 item)) const;

};
#include "LinkedList.cpp"
#endif