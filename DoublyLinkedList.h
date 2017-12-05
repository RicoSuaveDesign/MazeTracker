#pragma once
#include <iostream>
#include "LinkedListException.h"
template <class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void insertAtFront(const T& elem);
	void insertAtRear(const T& elem);
	T& at(int loc);
	int size();
	bool removeFromFront(T& elem);
	bool removeFromRear(T& elem);
	bool first(T& elem);
	bool next(T& elem);
	bool previous(T& elem);
	bool last(T& elem);
	bool isEmpty();
	bool find(const T& elem);
	bool remove();
	bool remove(const T& elem);
	T& operator[] (int index);
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
	Node* p_current;

};
//
template <class T>
DoublyLinkedList <T>::DoublyLinkedList()
{
	p_head = 0;
	p_tail = 0;
	numElements = 0;
}
template <class T>
int DoublyLinkedList<T>::size()
{
	int retVal = numElements;
	return retVal;
}
template <class T>
void DoublyLinkedList <T>::insertAtFront(const T& elem)
{
	Node* p_newNode = new Node;
	Node* p_insert; // temp ptr variable to hold the original head value
	p_newNode -> data = elem;
	p_newNode -> p_previous = 0;
	if(isEmpty())
	{
		p_newNode -> p_next = 0;
		p_tail = p_newNode;
	}
	else
	{
		p_insert = p_head; // points to orig head
		p_insert -> p_previous = p_newNode; // old head's prev points to new head
		p_newNode -> p_next = p_insert; // new head pts to old head 
	}
	p_head = p_newNode; // head now pts to new head, which the next ptr pts to old head
	p_insert = 0; // null the temp ptr 
	numElements++;
	//cout << p_head -> data;
}
template <class T>
T& DoublyLinkedList <T>::operator[] (int index)
{
	return at(index);
}
template <class T>
void DoublyLinkedList <T>::insertAtRear(const T& elem)
{
	//cout << "WONK";
	Node* p_newNode = new Node;
	Node* p_insert; // temp ptr variable to hold the original tail value
	p_insert = p_tail; // points to orig tail
	p_newNode -> data = elem; 
	p_newNode -> p_next = 0; // null the next ptr 
	if(isEmpty())
	{
		p_newNode -> p_previous = 0; // previous is null if this is first insertion
		p_head = p_newNode; // therefore the tail is also the head
	}
	else
	{
		p_insert -> p_next = p_newNode; // old tail next pts to new tail
		p_newNode -> p_previous = p_insert; // new tail prev pts to old tail
	}
	p_tail = p_newNode; // tail is now new node
	p_newNode = 0; // null temp ptr
	numElements++;
	//cout << p_tail -> data;
}
template <class T>
bool DoublyLinkedList<T>::first(T& elem)
{
	bool retVal = false;
	if(!isEmpty())
	{
		retVal = true;
		p_current = p_head;
		elem = p_current -> data;
	}
	return retVal;
}
template <class T>
bool DoublyLinkedList <T>::next(T& elem)
{
	bool retVal = false;
	if(p_current != p_tail && !isEmpty())
	{
		p_current = p_current -> p_next;
		elem = p_current -> data;
		retVal = true;
	}

	return retVal;
}
template <class T>
bool DoublyLinkedList<T>::previous(T& elem)
{
	bool retVal = false;
	if(p_current != p_head && !isEmpty())
	{
		retVal = true;
		p_current = p_current -> p_previous;
		elem = p_current -> data;
	}
	return retVal;
}
template <class T>
bool DoublyLinkedList<T>::last(T& elem)
{
	bool retVal = false;
	if(!isEmpty())
	{
		p_current = p_tail;
		elem = p_current -> data;
		retVal = true;
	}
	return retVal;
}
template <class T>
bool DoublyLinkedList <T>::isEmpty()
{
	bool retVal = false;
	if(numElements == 0)
		retVal = true;
	return retVal;
}
template <class T>
bool DoublyLinkedList <T>::removeFromFront(T& elem)
{
	bool retVal = false;
	p_current = p_head;
	elem = p_head -> data;
	retVal = remove();
	return retVal;
}
template <class T>
bool DoublyLinkedList <T>::removeFromRear(T& elem)
{
	bool retVal = false;
	p_current = p_tail;
	elem = p_tail -> data;
	retVal = remove();
	return retVal;
}
template <class T>
bool DoublyLinkedList <T>::remove()
{
	//cout << size();
	bool retVal = false;
	if(!isEmpty())
	{
		if(numElements == 1)
		{
			delete p_current;
			p_current = 0;
			p_head = 0;
			p_tail = 0;
		}
		else
		{
			Node* p_remove;
			p_remove = p_current; // temp ptr to orig current
			if(p_current == p_tail)
			{
				p_current = p_current -> p_previous; // if we're at the end and head != tail, pt backwards
				p_tail = p_current; // current is now the tail
				p_tail -> p_next = 0; // null the next ptr
				
			}
			else
			{
				if(p_current == p_head)
				{
					p_current = p_current -> p_next;
					p_head = p_current; // i feel like a total chump to nest this in here rather than figure out a better way
					p_head -> p_previous = 0; // null the previous
				}
				else
				{
					p_current = p_current -> p_next; // otherwise, current pts to next
					p_current -> p_previous = p_remove -> p_previous;
					p_current -> p_previous -> p_next = p_current; // Ah yes the scalene triangle, a.k.a the ptr to ptr to ptr I remember from class
				}
			}
			delete p_remove; // delete data at orig current
			p_remove = 0; // null the ptr
		}
		retVal = true; // regardless of orig size, if something was removed retval is true
		numElements --; // and numElements decreases
	}
	return retVal;
}
template <class T>
bool DoublyLinkedList<T>::remove(const T& elem)
{
	bool retVal = false;
	if(!isEmpty())
	{
		p_current = p_head;
		while(true)
		{
			if(p_current -> data == elem)
				retVal = remove();
			if(p_current == p_tail)
				break;
			else
				p_current = p_current -> p_next;
		}
	}
	return retVal;
}
template <class T>
bool DoublyLinkedList<T>::find(const T& elem)
{
	bool retVal = false;
	if(!isEmpty())
	{
		p_current = p_head;
		while(p_current -> data != elem)
		{
			if(p_current == p_tail)
				break;
			p_current = p_current -> p_next;
			if(p_current -> data == elem)
				retVal = true;
		}
	}
	else
	{
		// you cant find shit in an empty linkedlist, dumbass!
	}
	return retVal;
}
template <class T>
T& DoublyLinkedList <T>::at(int loc)
{
	p_current = p_head;
	if(!isEmpty())
	{
		if(loc >= numElements)
		{
			cout << "poop";
			LinkedListException f;
			throw f;
		}
		else if(loc == 0)
			return p_head -> data; // if u make any changes to these conditionals, remember your curly braces!!!!
		else if(loc == numElements - 1)
			return  p_tail -> data;
		else
		{
			int currentspot = 0;
			while(currentspot != loc)
			{
				currentspot++;
				p_current = p_current -> p_next;
			}
			return p_current -> data;
		}
	}
	else
	{
		LinkedListException f;
		throw f;
	}
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while(numElements > 0)
	{
		p_current = p_head;
		remove();
	}
}