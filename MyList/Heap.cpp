#include <iostream>
#include "Heap.h"
#include"HeapNode.h"
using namespace std;

template <typename T>
HeapNode<T>::HeapNode(const T& data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

template <typename T>
Heap<T>::Heap(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->root = nullptr;
	this->last = nullptr;
}

template <typename T>
void Heap<T>::addKey(const T& key) {
	if (this->size + 1 > this->capacity) {
		//error
	}
	else if (this->root == nullptr) {
		this->root = new HeapNode<T>(key);
		this->last = this->root;
	}
	else if (this->root == this->last) {
		this->root->left = new HeapNode<T>(key);
		this->root->left->parent = this->root;
		this->last = this->root->left;
		fixUp();
	}
	else if (this->last->parent->left == this->last) {
		HeapNode<T> *tmp = new HeapNode<T>(key);
		tmp->parent = this->last->parent;
		this->last->parent->right = tmp;
		this->last = tmp;
		fixUp();
		//this->last->parent->right = new HeapNode<T>(key);
	}
	else if (this->last->parent->right == this->last) {
		HeapNode<T>* tmp = this->last->parent;
		while (tmp == tmp->parent->right) {
			tmp = tmp->parent;
		}
		tmp = tmp->parent->right;
		while (tmp->left) {
			tmp = tmp->left;
		}
		tmp->left = new HeapNode<T>(key);
		tmp->left->parent = tmp;
		this->last = tmp->left;
		fixUp();
	}
	this->size++;
}

template <typename T>
void Heap<T>::fixUp() {
	if (this->last->data > this->lsst->parent->data) {
		HeapNode<T>* tmp = this->last;
		while (tmp->data > tmp->parent->data & tmp != this->root) {
			swap(tmp, tmp->parent);
			
			/*T a = tmp->data;
			tmp->data = tmp->parent->data;
			tmp->parent->data = a;
			*/
			tmp = tmp->parent;
			
		}
	}
}

template <typename T>
void Heap<T>::swap(HeapNode<T>* child, HeapNode<T>* parent) {
	T a = child->data;
	child->data = parent->data;
	parent->data = a;
}

template <typename T>
bool Heap<T>::find(const T& key) {
	int result = search(this->root, key);
	if (result > 0) return true;
	else return false;
}

template <typename T>
int Heap<T>::search(HeapNode<T>* root, const T& key) {
	if (!root) return 0;
	if (root->data == key) return 1;
	return Heap<T>::search(root->left, key) + Heap<T>::search(root->right, key);
}

template <typename T>
void Heap<T>::print() {
	straight(this->root);
}

template <typename T>
void Heap<T>::straight(HeapNode<T>* root)
{
	if (!root)
		return;
	printf("%d. \"%s\"\n", root->info);
	straight(root->left);
	straight(root->right);
}

template <typename T>
T Heap<T>::getMax() {
	return this->root->data;
}

template <typename T>
void Heap<T>::remove(const T& key) {
	T tmp = this->root->data;

}

template <typename T>
void Heap<T>::fixDown(HeapNode<T>* node) {

}

