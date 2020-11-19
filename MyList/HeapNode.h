#pragma once
template <typename X>
class HeapNode {
	//Constructor
	HeapNode(const X& data);

	X data;

	HeapNode* left;
	HeapNode* right;
	HeapNode* parent;
};