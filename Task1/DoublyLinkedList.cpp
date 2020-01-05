#include "DoublyLinkedList.h"
#include <iostream>

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {}

template<class T>
Node<T>* DoublyLinkedList<T>::getHead() const {
	return head;
}

template<class T>
Node<T>* DoublyLinkedList<T>::getTail() const {
	return tail;
}

template<class T>
void DoublyLinkedList<T>::add(Node<T>* data) {
	if (head == nullptr) {
		head = data;
		tail = data;
		data->setNext(nullptr);
		data->setPrev(nullptr);
		list_size++;
	}
	else {
		tail->setNext(data);
		data->setPrev(tail);
		data->setNext(nullptr);
		tail = data;
		list_size++;
	}
}

template<class T>
bool DoublyLinkedList<T>::add(Node<T>* data, int pos) {
	if (pos >= list_size || pos < 0) {
		return false;
	}

	if (pos == 0) {
		if (head == nullptr) {
			head = data;
			tail = data;
			list_size++;
		}
		else {
			head->setPrev(data);
			data->setNext(head);
			head = data;
			list_size++;
		}
	}
	else {
		if (pos >= list_size / 2) {
			Node<T>* temp = head;
			int i = 0;
			while (temp) {
				if (i == pos) {
					data->setPrev(temp->getPrev());
					temp->getPrev()->setNext(data);
					temp->setPrev(data);
					data->setNext(temp);
					list_size++;
					return true;
				}
				else {
					i++;
					temp = temp->getNext();
				}
			}
		}
		else {
			Node<T>* temp = tail;
			int i = list_size - 1;
			while (temp) {
				if (i == pos) {
					data->setPrev(temp->getPrev());
					temp->setPrev(data);
					data->setNext(temp);
					list_size++;
					return true;
				}
				else {
					i--;
					temp = temp->getPrev();
				}
			}
		}
	}
	return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(int pos) {
	if (pos >= list_size || pos < 0) {
		return false;
	}

	if (pos == 0) {
		if (head == nullptr) {
			return false;
		}
		else {
			head = head->getNext();
			head->setPrev(nullptr);
		}
	}
	else {
		if (pos >= list_size / 2) {
			Node<T>* temp = head;
			int i = 0;
			while (temp) {
				if (i == pos) {
					temp->getPrev()->setNext(temp->getNext());
					temp->getNext()->setPrev(temp->getPrev());
					list_size--;
					return true;
				}
				else {
					i++;
					temp = temp->getNext();
				}
			}
		}
		else {
			Node<T>* temp = tail;
			int i = list_size - 1;
			while (temp) {
				if (i == pos) {
					temp->getPrev()->setNext(temp->getNext());
					temp->getNext()->setPrev(temp->getPrev());
					list_size--;
					return true;
				}
				else {
					i--;
					temp = temp->getPrev();
				}
			}
		}
	}
	return true;
}

template<class T>
bool DoublyLinkedList<T>::replace(Node<T>* old_node, Node<T>* new_node) {
	if (old_node == nullptr || new_node == nullptr || list_size < 1) {
		return false;
	}

	if (old_node == new_node) {
		return true;
	}

	Node<T>* old_prev = old_node->getPrev();
	Node<T>* old_next = old_node->getNext();
	Node<T>* new_prev = new_node->getPrev();
	Node<T>* new_next = new_node->getNext();

	if (old_node == head) {
		if (new_node == tail) {
			tail = old_node;
		}
		head = new_node;
	}
	else if (new_node == head) {
		if (old_node == tail) {
			tail = new_node;
		}
		head = old_node;
	}
	
	if (old_node == new_next) {
		new_next = new_node;
	}
	if (new_node == old_next) {
		old_next = old_node;
	}

	new_node->setPrev(old_prev);
	if (old_prev) {
		old_prev->setNext(new_node);
	}

	new_node->setNext(old_next);
	if (old_next) {
		old_next->setPrev(new_node);
	}

	old_node->setPrev(new_prev);
	if (new_prev) {
		new_prev->setNext(old_node);
	}

	old_node->setNext(new_next);
	if (new_next) {
		new_next->setPrev(old_node);
	}

	return true;
}

template<class T>
const int DoublyLinkedList<T>::search(Node<T>* data) const {
	if (data == nullptr) {
		return -1;
	}

	Node<T>* temp = head;
	int i = 0;

	while (temp) {
		if (temp == data) {
			return i;
		}
		i++;
		temp = temp->getNext();
	}
	return -1;
}

template<class T>
Node<T>* DoublyLinkedList<T>::getNode(int pos) const {
	if (pos >= list_size || pos < 0) {
		return nullptr;
	}

	if (pos == 0) {
		return head;
	}
	else {
		if (pos >= list_size / 2) {
			Node<T>* temp = head;
			int i = 0;
			while (temp) {
				if (i == pos) {
					return temp;
				}
				else {
					i++;
					temp = temp->getNext();
				}
			}
		}
		else {
			Node<T>* temp = tail;
			int i = list_size - 1;
			while (temp) {
				if (i == pos) {
					return temp;
				}
				else {
					i--;
					temp = temp->getPrev();
				}
			}
		}
	}
}

template<class T>
const void DoublyLinkedList<T>::display_forward() const {
	Node<T>* temp = head;
	while (temp) {
		std::cout << temp->getData() << std::endl;
		temp = temp->getNext();
	}
}

template<class T>
const void DoublyLinkedList<T>::display_backward() const {
	Node<T>* temp = tail;
	while (temp) {
		std::cout << temp->getData() << std::endl;
		temp = temp->getPrev();
	}
}

template<class T>
const int DoublyLinkedList<T>::size() const {
	return list_size;
}

template class DoublyLinkedList<int>;