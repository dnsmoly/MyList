#include <iostream>
#include <windows.h>
#include "MyList.h"
#include "Node.h"
#include "Bin.h"
#include "Heap.h"
#include "HeapNode.h"
using namespace std;

template <typename B>
Node<B>::Node(const B& t) {
	this->data = t;
	this->next = nullptr;
}

template <typename T>
MyList<T>::MyList(int capacity) {
	this->capacity = capacity;
	head = nullptr;
}

template <typename T>
MyList<T>::~MyList() {
	while (head != nullptr) {
		remove();
	}
}

template <typename T>
void MyList<T>::remove() {
	if (head != nullptr) {

		Node<T>* tmp = head->next;
		delete head;
		head = tmp;
	}
	else throw bad_weak_ptr();
}

template <typename T>
void MyList<T>::append(const T& item) {
	if (size() + 1 > capacity) {
		throw invalid_argument("Out of range");
	}
	else {
		Node<T>* newNode = new Node<T>(item);
		newNode->next = head;
		head = newNode;
	}
	
}

template <typename T>
void MyList<T>::removeBack() { //add
	if (head != nullptr) {
		Node<T>* tmp = head;

		while (tmp->next != nullptr) {
			if (tmp->next->next == nullptr) {
				delete tmp->next;
				tmp->next = nullptr;
			}
			else tmp = tmp->next;
		}
	}
	else throw bad_weak_ptr();
}

template <typename T>
void MyList<T>::pushBack(const T& item) {
	if (head != nullptr) {
		Node<T>* tmp = head;

		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(item);
	}
	else if (size() + 1 > capacity) {
		throw invalid_argument("Out of range");
	}
	else {
		head = new Node<T>(item);
	}
}

template <typename T>
void MyList<T>::remove(const T& item) { // remove an item and all of it`s copies from the List
	if (search(item)) {
		if (head != nullptr) {
			while (head->data == item) {
				Node<T>* buff = head;
				head = head->next;
				delete buff;
			}

			Node<T>* tmp = head;
			Node<T>* toRemove;

			while (tmp->next != nullptr) {
				if (tmp->next->data != item) {
					tmp = tmp->next;
				}
				else {
					toRemove = tmp->next;
					tmp->next = toRemove->next;
					delete toRemove;
				}
			}
			if (tmp->data == item) removeBack();
		}
		else {
			throw bad_weak_ptr();
		}
	}
	else {
		throw invalid_argument("No such item");
	}
	
}
template <typename T>
bool MyList<T>::search(const T& item) {
	int a = 0;
	Node<T> *tmp = head;
	while (tmp) {
		if (tmp->data == item) a++;
		tmp = tmp->next;
	}
	if (a > 0) return true;
	else return false;
}

template <typename T>
T MyList<T>::front() {
	if (head != nullptr) return head->data;
	else {
		throw bad_weak_ptr();
	}
}

template <typename T>
T MyList<T>::back() {
	if (head != nullptr) {
		Node<T>* tmp = head;

		while (tmp->next) {
			tmp = tmp->next;
		}
		return tmp->data;
	}
	else {
		throw bad_weak_ptr();
	}
}

template <typename T>
int MyList<T>::size() {
	unsigned int s = 0;
	if (head != nullptr) {
		Node<T>* tmp = head;
		s++;
		while (tmp->next != nullptr) {
			s++;
			tmp = tmp->next;
		}
		return s;
	}
	else {
		return s;
	}

}

template <typename T>
void MyList<T>::print() {
	if (head != nullptr) {
		Node<T>* tmp = head;
		cout << '{' << head->data;
		while (tmp->next) {
			tmp = tmp->next;
			cout << ", " << tmp->data;
		}
		cout << '}' << endl;
	}
	else cout << "List is empty";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//int a = 1;
	char action;
	char a;
	int num;
	Bin n;
	MyList<int> test;
	cout << "Press 1 to start linkedList program" << endl;
	cout << "Press 2 to start Binary Number program" << endl;
	
	cin >> action;
	
	
	switch (action) {
	case '1':
		cout << "Введите размер" << endl;
		cin >> num;
		test = MyList<int>(num);
	/*}
	catch (bad_weak_ptr a) {
		cout << a.what() << endl;;
	}
	catch (invalid_argument a) {
		cout << a.what() << endl;
	}*/

		cout << "Commands:" << endl;
		cout << "1 - Add element to the front\n2 - Remove head element\n3 - Remove element and all it`s copies" << endl;
		cout << "4 - Remove back element\n5 - Add element to the back \n6 - print the list" << endl;
		cout << "7 - Get size\n8 - commands\n0 - stop" << endl;
			
		do {
			cout << "Введите команду" << endl;
			cin >> a;
			switch (a) {
			case '1':
				cout << "Введите число" << endl;
				cin >> num;
				try {
					test.append(num);
				}
				catch (invalid_argument a) {
					cout << a.what() << endl;
				}
				
				break;
			case '2':
				cout << "Remove head" << endl;
				try {
					test.remove();
				}
				catch (bad_weak_ptr a) {
					cout << a.what() << endl;
				}
				break;
			case '3':
				cout << "Введите число" << endl;
				cin >> num;
				try {
					test.remove(num);
				}
				catch (bad_weak_ptr a) {
					cout << a.what() << endl;
				}
				catch (invalid_argument a) {
					cout << a.what() << endl;
				}
				break;
			case '4':
				cout << "Remove back element" << endl;
				try {
					test.removeBack();
				}
				catch (bad_weak_ptr a) {
					cout << a.what() << endl;
				}
				break;
			case '5':
				cin >> num;
				try {
					test.pushBack(num);
				}
				catch (invalid_argument a) {
					cout << a.what() << endl;
				}
				break;
			case '6':
				test.print();
				break;
			case '7':
				cout << "Size: " << test.size() << endl;
				break;
			case '8':
				cout << "Commands:" << endl;
				cout << "1 - Add element to the front\n2 - Remove head element\n3 - Remove element and all it`s copies" << endl;
				cout << "4 - Remove back element\n5 - Add element to the back \n6 - print the list" << endl;
				cout << "7 - Get size\n8 - commands\n0 - stop" << endl;
				break;
			case '0':
				cout << "Stop";
				break;
			}
		} while (a != '0');
	break; 
	/*case '2':

			/*MyList<Bin> binList;
			int num1;
			string num2;
			char action;
			char number;
			Bin a = Bin(0);
			Bin b = Bin(0);
			Bin c = Bin(0);

			cout << "\nBinary number" << endl;

			cout << "+, -, /, * - operations" << endl;
			cout << "s - stop" << endl;
			cout << "First enter both the number, then choose the operation" << endl;

			do {
				cout << "\nWhat do you want to do?\n1 - count\ns - stop" << endl;
				cin >> action;
				try {
					if (action == '1') {
						cout << "Enter the first number" << endl;
						cin >> num1;
						a = Bin(num1);
					}
					if (action == 's') break;
					cout << "Enter the second number" << endl;
					cin >> num1;
					b = Bin(num1);
					cout << "Enter operation:" << endl;
					cin >> action;
					switch (action) {
					case '+':
						a = a + b;
						cout << "anwser: " << endl;
						a.intPrint();
						a.biPrint();
						break;
					case '-':
						a = a - b;
						cout << "answer: " << endl;
						a.intPrint();
						a.biPrint();
						break;
					case '*':
						a = a * b;
						cout << "answer: " << endl;
						a.intPrint();
						a.biPrint();
						break;
					case '/':
						a = a / b;
						cout << "answer: " << endl;
						a.intPrint();
						a.biPrint();
						break;
					case 's':
						break;
					}
				}
				catch (invalid_argument a) {
				cout << a.what() << endl;
				}

			} while (action != 's');
	break;*/
	}

}
	

	




