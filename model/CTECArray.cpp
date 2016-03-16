/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: jlin3312
 */

#include "CTECArray.h"
#include <iostream>
#include <assert.h>

using namespace std;

/**
 * this initializes the other methods.
 */
template <class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;
//Defensive code
	assert(size >0);

for(int index = 0; index < size; index++)
	{
	if(head != nullptr)
	{
		//regular ArrayNode being made
		ArrayNode<Type> * nextNode = new ArrayNode<Type>();//Pointer to make space for the nodes so they are available  off the stack
		//::
		nextNode->setNext(head);
		//set head to address of next node
		this->head = nextNode;
	}
		else
		{
	//first ArrayNode needs to be made.
	ArrayNode<Type> * firstNode = new ArrayNode<Type>();
	this->head = firstNode;
		}
	}
}
/**
 * this destroys unused nodes int the array.
 * this is the destrutor.
 */
template <class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for(int index = 0; index < size; index++)
	{
		//check ArrayNode has pointer to nxt.
		if(deleteMe->getNext() != nullptr)
		{
			//set head to nxt pointer
			head = deleteMe->getNext();
			//delete the pointer
			deleteMe->setNext(nullptr);

		}
		//delete the ArrayNode
					delete deleteMe;
					//point to the next Node.
					deleteMe = head;

	}

	delete head;
}

/**+
 *
 * .
 *
 * this gets the size of the array.
 * this gives the user the value you need.
 */
template <class Type>
int CTECArray<Type> ::  getSize()
{
	return this->size;
}
template <class Type>
void CTECArray<Type> ::  set(int position,const Type& value)
{

	assert(position < size && position >= 0);
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			if(spot != position)
			{
				current = current->getNext();
			}

			else
			{
				current->setValue(value);
			}

		}

}

/*
 1. check array2. point to head
 3. loop over till node is found
 4. return index if index or -1 not found
 
 */
 
template <class Type>
int CTECArray<Type> :: indexOf(Type searchValue)
{
    assert(this->size > 0);
    
    ArrayNode<Type> * current = head;
    int indexNotFound = -1;
    
    for(int index = 0; index < this->size; index++)
    {
        
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getValue;
        }
        
    }
    
    return indexNotFound;
}

template <class Type>
int CTECArray<Type> :: nextIndexOf(int startingIndex,Type searchValue)
{
    assert(this->size > 0);
    aasert(startingIndex >= 0 && startingIndex < this->si);
    
    ArrayNode<Type> * current = head;
    int indexNotFound = -1;
    
    for(int index = 0; index <startingIndex; index++)
    {
        current = current->getNext();
    }
    
    for(int index = startingIndex; index < this->size; index++)
    {
        
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getValue;
        }
        
    }
    
    return indexNotFound;
}


/**
 * this gets a value from the array
 * <param> int position this is the spot in the array.
 */

template <class Type>
Type CTECArray<Type> ::  get(int position)
{
	//I'm out of bounds and need to do somthing about it.
	assert(position < size && position >= 0);
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			//Not in the right spot go to next spot.
			if(spot != position)
			{
				current = current->getNext();
			}

			else
			{
				return current->getValue();
			}
		}

    return current->GetValue;
}


