#pragma once
template <typename B>
class Node // node class
{
public:
	Node* next; // link to the next element
	B data; // data of the node

	Node(const B& t);
};
