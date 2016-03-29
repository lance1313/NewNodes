/*
 * CTECList.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: jlin3312
 */

#include "CTECList.h"
#include <assert.h>

template <class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;



}
template <class Type>
CTECList<Type>::~CTECList()
{

	ArrayNode<Type> * head = new ArrayNode<Type>();
	ArrayNode<Type> * tail = new ArrayNode<Type>();
	ArrayNode<Type> * current;
	for(int index = 0;  index < size; index++)
	{
	ArrayNode<Type> * temp = current;
		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	size =0;
	head = nullptr;
	tail = nullptr;
}
/**
 *initialize the size of the list
 */
template <class Type>
int CTECList<Type>::setSize()
{
return this->size;
}
/**
 *Makes a new head and moves it to the next front node
 */
template <class Type>
Type CTECList<Type>::removeFromFront()
{
	Type thingToRemove;
//find the next pot
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();
	//get what head is holding
	thingToRemove = this->head->getValue();
	//remove head
	delete head;
	//move head to next
	head = newHead;
this->calculateSize;
	return thingToRemove;
}
/**
 *this removes the last node ,and moves tail to the next node.
 *this create return variable
 *this loop the next to the last node
 *this grab the value from the last node
 *this delete last node
 *this set new last node
 */
template <class Type>
Type CTECList<Type>::removeFromEnd()
{
	//defencive code
	assert(this->size > 0);
	Type returnValue;
	ArrayNode<Type> * newTail = new ArrayNode<Type>();
	ArrayNode<Type> * current = ArrayNode<Type>();

	if(size == 1)
	{
		ArrayNode<Type> * toRemove = tail;
		returnValue = removeFromFront();
		tail = nullptr;
	}

	else
	{
ArrayNode<Type> * current = head;
for(int index = 0; index < size-1; index ++)
{
	current = current->getNext();
}


	returnValue = tail->getValue();
		delete tail;
		current = newTail;
		calculateSize();
	current->setNext(nullptr);
	}



	return returnValue;
}
/**
 *remove node from specified spot
 */
template <class Type>
Type CTECList<Type>::removeFromIndex(int index)
{

	assert(index >= 0);
	assert(index < size);
	assert(size > 0);
	ArrayNode<Type> * deleteMe = new ArrayNode<Type>();
	Type thingToRemove;
	ArrayNode<Type> * newNext = new ArrayNode<Type>();
	ArrayNode<Type> * current = new ArrayNode<Type>();
	ArrayNode<Type> * previous = new ArrayNode<Type>();

	if(index == 0)
	{

		thingToRemove = removeFromFront();
	}

	else if(index == size-1)
	{
		thingToRemove = removeFromEnd();
	}
	else

	{


		for(int index = 0; index < size  ; index++)
		{

			current = current->next();

		}
		ArrayNode<Type> * previous = newNext;
		delete deleteMe;
		this->calculateSize;
		return deleteMe;
	}
}
/**
 * sets the value in the list
 */
template <class Type>
Type CTECList<Type>::set(int index, const Type& value)
{
	assert(this->size > 0);
		ArrayNode<Type> * previous = ArrayNode<Type>();
		ArrayNode<Type> * insert = previous;
		ArrayNode<Type> * current = ArrayNode<Type>();
		ArrayNode<Type> * newNode = ArrayNode<Type>();


		if(index == 0)
		{
			current->addToFront();
		}

		else if( index == size - 1)
		{
			current->addToEnd();
		}

		else
		{

		for(index = 0;index < size -1;index++)
			{
			current = current->next;
			}
		current = head;
		return current->getValue();
		calculateSize();

		}
}

/**
 *get value from the first node
 */
template <class Type>
Type CTECList<Type>::getFront()
{
	return head->getValue();
}
/**
 *get value from last node
 */
template <class Type>
Type CTECList<Type>::getEnd()
{
	return tail->getValue();
}
/**
 *get value from specified spot
 */
template <class Type>
Type CTECList<Type>::getFromIndex(int index)
{
	assert(this->size > 0);
	assert(index >= size);
	ArrayNode<Type> * current = new ArrayNode<Type>();
	ArrayNode<Type> * next = new ArrayNode<Type>();

	if(index == 0)
			{
				current->getFront;
			}

			else if( index == size - 1)
			{
				current->getEnd();
			}

			else
			{
	for(index = 0;index < size;index++)
		{
		current = current->getNext();
		}
			}
	return  current->getValue();//  uqd9g o8he178w5

}
/**
 *add the the front of the list
 */
template <class Type>
void CTECList<Type>::addToFront(const Type& value)
{
	ArrayNode<Type> * newHead;
	ArrayNode<Type> * current = new ArrayNode<Type>();

	

	if(size ==0)
	{
		tail = head;
	}

    current->setValue(value);
    current->setNext(head);
newHead = head;


	calculateSize();
}
/**
 *add to the end of the list
 */
template <class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
    ArrayNode<Type> * newTail;
	ArrayNode<Type> * current;
    current->setValue(value);
    current->setNext(tail);
    tail= newTail;

	calculateSize();
}
/**
 *
 *
 */
template <class Type>
void CTECList<Type>::addToIndex(int index,const Type& value)
{
	assert(this->size > 0);
	ArrayNode<Type> * previous = ArrayNode<Type>();
	ArrayNode<Type> * insert = previous;
	ArrayNode<Type> * current = ArrayNode<Type>();
	current = head;

	if(index == 0)
	{
		current->addToFront();
	}

	else if( index == size - 1)
	{
		current->addToEnd();
	}

	else
	{

	for(index = 0;index < size -1;index++)
		{


		current = current->getNext();
		}
	}
	this->calculateSize;

}


template <class Type>
void CTECList<Type>:: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    Type temp = getFromIndex(indexOne);
    set(indexOne, getFromIndex(indexTwo));
    set(indexTwo, temp);
}

template <class Type>
void CTECList<Type> :: calculateSize()
{

	assert(size >= 0);
	int count = 0;

	if(head == nullptr)
	{
		size = 0;
	}

	else
	{
		count++;
		ArrayNode<Type> * current = head;
		while(current->getNext() != nullptr)
		{

			count++;
			//use to leave the loop
			current = current->getNext();
		}
		size = count;
	}
}

