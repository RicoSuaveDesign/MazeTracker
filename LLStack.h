#pragma once
#include "DoublyLinkedList.h"
#include "StackUnderflowException.h"

template <class T>
class LLStack
{
public:
	LLStack();
	~LLStack();
	void push(const T& elem);
	void pop(T& elem);
	void top(T& elem); // note to self don't forget your stack underflow exception
	bool isEmpty();
	int size();
private:
	DoublyLinkedList <T> base;
};
//
template <class T>
LLStack<T>::LLStack()
{

}
template <class T>
void LLStack<T>::push(const T& elem)
{
	base.insertAtFront(elem);
}
template <class T>
void LLStack<T>::pop(T& elem)
{
	if(size() != 0)
		base.removeFromFront(elem);
	else
	{
		StackUnderflowException n;
		throw n;
	}	
}
template <class T>
void LLStack<T>::top(T& elem)
{
	if(size() !=0)
		base.first(elem);
	else
	{
		StackUnderflowException n;
		throw n;
	}
}
template <class T>
bool LLStack<T>::isEmpty()
{
	bool retVal;
	retVal = base.isEmpty();
	return retVal;
}
template <class T>
int LLStack<T>::size()
{
	int retVal;
	retVal = base.size();
	return retVal;
}
template <class T>
LLStack <T>::~LLStack()
{
	T junk;
	while(size() > 0)
		base.removeFromFront(junk);
}