#pragma once
#include "HeapNode.h"
template <typename T>
class Heap {
	
	int size; // current size of heap
	int capacity; // max number of elements

public:
	//Constructor
	Heap(int capacity = 10);

	~Heap();

	void addKey(const T& key);
	bool find(const T& key);
	void remove(const T& key);
	void print();
	T getMax();


private:

	
	HeapNode<T>* root;
	HeapNode<T>* last;

	void straight(HeapNode<T>* root);
	int search(HeapNode<T>* root, const T& key);
	void swap(HeapNode<T>* child, HeapNode<T>* parent);
	void fixUp();
	void fixDown(HeapNode<T>* node);

};
