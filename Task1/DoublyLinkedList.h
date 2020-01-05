#pragma once
#include "Node.h"

template<class T>
class DoublyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int list_size;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	Node<T>* getHead() const;
	Node<T>* getTail() const;
	void add(Node<T>* data);
	bool add(Node<T>* data, int pos);
	bool remove(int pos);
	bool replace(Node<T>* old_node, Node<T>* new_node);
	const int search(Node<T>* data) const;
	Node<T>* getNode(int pos) const;
	const void display_forward() const;
	const void display_backward() const;
	const int size() const;
};