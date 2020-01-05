#include "Node.h"

template<class T>
Node<T>::Node(T data) : next(nullptr), prev(nullptr), data(data) {}

template<class T>
Node<T>::~Node() {}

template<class T>
const T Node<T>::getData() const {
	return this->data;
}

template<class T>
void Node<T>::setData(T data) {
	this->data = data;
}

template<class T>
Node<T>* Node<T>::getNext() const {
	return this->next;
}

template<class T>
void Node<T>::setNext(Node* next) {
	this->next = next;
}

template<class T>
Node<T>* Node<T>::getPrev() const {
	return this->prev;
}

template<class T>
void Node<T>::setPrev(Node* prev) {
	this->prev = prev;
}

template class Node<int>;