/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: jlin3312
 */

#include "ArrayNode.h"
//#include<iostream>
/**
 *
 */
template <class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>()//a super construtor.
{
	this->next = nullptr;
	//this->pointers = nullptr;

}
/**
 * <param>const Type shows that it extends node.cpp
 */
template <class Type>
ArrayNode<Type> :: ArrayNode(const Type& value) : Node<Type>()
{
	this->next = nullptr;
	this->value = value;

}

/**
 * this is the construtor
 */
template <class Type>
ArrayNode<Type> :: ArrayNode(const Type& value, ArrayNode<Type> * next) : Node<Type>(value)
{
	this->next = next;
	this->value = value;
}

template <class Type>
ArrayNode<Type>::~ArrayNode()
{
	// TODO Auto-generated destructor stub
}
/**
 * this gets the adress of the last node
 */
template <class Type>
ArrayNode<Type> * ArrayNode<Type> :: getNext()
{
	return this->next;
}

/**
 * this sets the array head to the new node.
 */
template <class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next)
{
	this->next = next;
}
