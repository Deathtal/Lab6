#pragma once

template<class T>
class Node {
private:
	T data;
	Node* next;
	Node* prev;
public:
	Node(T data);
	~Node();
	const T getData() const;
	void setData(T data);
	Node* getNext() const;
	void setNext(Node* next);
	Node* getPrev() const;
	void setPrev(Node* prev);
};