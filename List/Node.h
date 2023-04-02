#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<class T>
class Node {
private:
	Node<T>* prev;
	T value;
	Node<T>* next;

public:

	Node() {
		prev = nullptr;
		next = nullptr;
	};

	Node(T value) {
		prev = nullptr;
		this->value = value;
		next = nullptr;
	};

	T getValue() const {
		return this->value;
	};

	void setValue(T value) {
		this->value = value;
	};

	Node<T>* getPrev() const {
		return prev;
	};

	void setPrev(Node* other) {
		prev = other;
	};

	Node<T>* getNext() const {
		return next;
	};

	void setNext(Node* other) {
		next = other;
	};


	~Node() {
		this->prev = nullptr;
		this->next = nullptr;
	};
};

#endif // NODE_H !

