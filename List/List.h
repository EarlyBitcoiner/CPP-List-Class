#ifndef LIST_H
#define LIST_H

#include "Node.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class List {
public:
	class iterator {
	private:
		Node<T>* curr;

	public:

		iterator(Node<T>* node) : curr(node) {};

		bool operator!=(const iterator& other) const {
			return curr != other.curr;
		}

		bool operator==(const iterator& other) const {
			return curr == other.curr;
		}

		T operator*() const {
			return curr->getValue();
		}

		iterator& operator++() {
			curr = curr->getNext();
			return *this;
		}

		iterator operator++(int) {
			iterator it = *this;
			curr = curr->getNext();
			return it;
		}

		Node<T>* getNode() {
			return curr;
		}
	};

	iterator begin() const {
		return iterator(head);
	}

	iterator end() const {
		return iterator(nullptr);
	}

private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:

	List() : size(0), tail(nullptr), head(nullptr) {};

	List(const List<T>& other) {
		head = nullptr;
		tail = nullptr;
		size = 0;

		Node<T>* curr = other.head;

		while (curr != nullptr) {
			push_back(curr->getValue());
			curr = curr->getNext();
		}


	};

	List<T>& operator=(const List<T> & other){
		if (this != &other) {
             // delete this list
			Node<T>* curr = head;

			while (curr != nullptr) {
				Node<T>* next = curr->getNext();
				delete curr;
				curr = next;
			}

			head = nullptr;
			tail = nullptr;
			size = 0;

			// Copy the other list
				curr = other.head;

			while (curr != nullptr) {
				push_back(curr->getValue());
				curr = curr->getNext();
			}
		}

		return *this;
	}

	bool empty() const {
		return head == nullptr;
	}

	int getSize() const {
		return size;
	};

	void push_back(T value) {

		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->setPrev(tail);
			tail->setNext(newNode);
			tail = newNode;
		}
		size++;
	};

	void push_front(T value) {

		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->setNext(head);
			head->setPrev(newNode);
			head = newNode;
		}

		size++;
	};

	T front() const {
		return this->head->getValue();
	};

	T back() const {
		return this->tail->getValue();
	};

	void remove(T value) {
		Node<T>* curr = head;

		while (curr != nullptr) {
			if (curr->getValue() == value) {
				if (curr == head) {
					head = curr->getNext();
					if (head != nullptr) {
						head->setPrev(nullptr);
					}
				}
				else if (curr == tail) {
					tail = curr->getPrev();
					tail->setNext(nullptr);
				}
				else {
					curr->getPrev()->setNext(curr->getNext());
					curr->getNext()->setPrev(curr->getPrev());
				}

				delete curr;
				size--;
				return;
			}

			curr = curr->getNext();
		}
	}

	void insert(iterator& pos, T value) {
		if (pos == end()) {
			push_back(value);
		}
		else if (pos == begin()) {
			push_front(value);
		}
		else {
			Node<T>* prev = pos.getNode()->getPrev();
			Node<T>* newNode = new Node<T>(value);

			newNode->setPrev(prev);
			newNode->setNext(prev->getNext());

			prev->getNext()->setPrev(newNode);
			prev->setNext(newNode);
			
		}

		size++;
	}
	
	void insert(T value) {
		
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->setPrev(tail);
			tail->setNext(newNode);
			tail = newNode;
		}
		size++;
	};

	void insert(T value, int pos) {
		if (pos < 0 || pos > size) {
			return;
		}

		if (pos == 0) {
			push_front(value);
		}
		else if (pos == size) {
			push_back(value);
		}
		else {
			Node<T>* curr = head;
			int i = 0;

			while (curr != nullptr && i < pos) {
				curr = curr->getNext();
				i++;
			}

			Node<T>* newNode = new Node<T>(value);
			newNode->setPrev(curr->getPrev());
			newNode->setNext(curr);
			curr->getPrev()->setNext(newNode);
			curr->setPrev(newNode);

			size++;
		}
	}

	string toString() const {

		if (empty())
			return "Empty";

		stringstream stream;
		Node<T>* curr = head;

		while (curr != nullptr) {
			stream << curr->getValue() << " ";
			curr = curr->getNext();
		}

		return stream.str();
	}

	~List() {
		if (head == nullptr)
			return;

		Node<T>* current = head;

		while (current->getNext() != nullptr) {
			current = current->getNext();
			Node<T>* temp = current->getPrev();
			delete temp;
		}

		delete current;
	};


};

#endif // !LIST_H

