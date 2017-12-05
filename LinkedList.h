#pragma once
#include <iostream>
template <class T>
class LinkedList
{
public:
	LinkedList();
	//~LinkedList();
	void insertAtFront(const T& elem);
	void insertAtRear(const T& elem);
	bool removeFromFront(T& elem);
	bool first(T& elem);
	bool next(T& elem);
private:
	struct Node
	{
		T data;
		Node* p_previous;
		Node* p_next;
	};
	Node* p_head;
	Node* p_tail;
	int numElements;
	int* p_currentNode;

};
//
template <class T>
LinkedList <T>::LinkedList()
{
	p_head = 0;
	numElements = 0;
}

template <class T>
void LinkedList <T>::insertAtFront(const T& elem)
{
	Node* p_newNode = new Node;
	Node* p_insert; // temp ptr variable to hold the original head value
	p_insert = p_head; // points to orig head
	p_newNode -> data = elem; 
	p_newNode -> p_previous = 0; 
	p_head = p_newNode;
	if(numElements == 0)
	{
		p_newNode -> p_next = 0;
	}
	else
	{
		p_newNode -> p_next = p_insert;
	}
	numElements++;
	//cout << p_head -> data;
}
template <class T>
void LinkedList <T>::insertAtRear(const T& elem)
{
	Node* p_newNode = new Node;
	Node* p_insert; // temp ptr variable to hold the original tail value
	p_insert = p_tail; // points to orig tail
	p_newNode -> data = elem; 
	p_newNode -> p_next = 0; 
	p_tail = p_newNode;
	if(numElements == 0)
	{
		p_newNode -> p_previous = 0;
	}
	else
	{
		p_newNode -> p_previous = p_insert;
	}
	numElements++;
	//cout << p_tail -> data;
}
template <class T>
bool LinkedList <T>::removeFromFront(T& elem)
{
	bool retVal = false;
	if(numElements > 0)
	{
		Node* p_remove;
		p_remove = p_head;
		p_head = p_head -> p_next;
		delete p_remove;
		p_remove = 0;
		retVal = true;
	}
	else
	{

	}
	return retVal;
}