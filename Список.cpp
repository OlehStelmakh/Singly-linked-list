﻿#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;


template<typename T>
class List
{
public:
	List(); //constructor
	~List(); //destructor

	void pop_front(); //delete the first element
	void push_back(T data); //add an element to the end of the list
	void clear(); //delete list
	int GetSize() { return Size; } //Number of elements in the list
	T& operator[](const int index); // overloaded operator []
	void push_front(T data); //add an element to the top of the list
	void insert(T data, int index); //add an element to the list by a given index
	void removeAt(int index); //delete an element from the list by a given index
	void pop_back(); //delete the last element in the list
	

private:

	template<typename T>
	class Node {
	public:

		Node * pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};

template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::pop_front() {
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::push_back(T data) {

	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::clear() {
	while (Size) {
		pop_front();
	}
}

template<typename T>
T & List<T>::operator[](const int index) {
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}

}

template<typename T>
void List<T>::pop_back() {
	removeAt(Size - 1);
}

int main() {

	List<int> lst; //create an instance of the List class

	int quantityOfNumbers;
	cout << "Input a quantity of numbers: ";
	cin >> quantityOfNumbers;
	
	srand(time(0));
	for (int i = 0; i < quantityOfNumbers; i++) {
		lst.push_back(rand() % 10);
	}

	cout << "[ ";
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i] << " ";
	}
	cout << "]" << endl;

	system("pause");
	return 0;
}
