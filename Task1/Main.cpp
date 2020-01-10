#include "DoublyLinkedList.h"
#include <iostream>

int main() {
	DoublyLinkedList<int> list;
	Node<int> a(1);
	Node<int> b(2);
	Node<int> c(3);
	Node<int> d(4);
	Node<int> e(5);
	Node<int> f(6);
	Node<int> g(7);
	Node<int> h(8);
	Node<int> i(9);

	list.add(&a);
	list.add(&b);
	list.add(&c);
	list.add(&d);
	list.add(&e);
	list.add(&f);
	list.add(&g);
	list.add(&h);
	list.add(&i);

	list.display_forward();
	std::cout << "display_forward, size: " << list.size() << std::endl;
	std::cout << std::endl;

	list.remove(4);
	std::cout << "remove(4): " << std::endl;

	list.display_backward();
	std::cout << "display_backward, size: " << list.size() << std::endl;
	std::cout << std::endl;

	list.add(&e, 4);
	std::cout << "add(&e, 4): " << std::endl;

	list.display_forward();
	std::cout << "display_forward, size: " << list.size() << std::endl;
	std::cout << std::endl;

	list.replace(list.getHead(), list.getTail());
	std::cout << "replace(head, tail): " << std::endl;

	list.display_backward();
	std::cout << "display_backward, size: " << list.size() << std::endl;
	std::cout << std::endl;

	list.replace(list.getNode(list.search(&i)), list.getNode(list.search(&a)));
	std::cout << "replace(getNode(search(&i)), getNode(search(&i))): " << std::endl;

	list.display_forward();
	std::cout << "display_forward, size: " << list.size() << std::endl;
	std::cout << std::endl;

	list.replace(&d, &c);
	std::cout << "replace(&d, &c): " << std::endl;

	list.display_forward();
	std::cout << "display_forward, size: " << list.size() << std::endl;
	std::cout << std::endl;
}