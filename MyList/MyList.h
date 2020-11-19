#pragma once
#include "Node.h"
template <typename T>
class MyList
{
public:

	MyList(int capacity = 10);
	~MyList();

	void remove(); // remove last added item
	void remove(const T&); // remove an element and all it`s copies
	void removeBack(); // remove last element
	void append(const T&); // add an element
	void pushBack(const T&); // add an element to the end of the list
	T front(); // returns the head element
	T back(); // returns the last element
	//void clear();
	void print(); // prints the list
	int size(); // returns the size of the list


private:

	int capacity;
	bool search(const T& item);
	Node<T>* head; // link to the head element

};