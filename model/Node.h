/*
 * Node.h
 *
 *  Created on: Jan 27, 2016
 *      Author: jlin3312
 */

#ifndef SRC_MODEL_NODE_H_
#define SRC_MODEL_NODE_H_
#include <iostream>

template<class Type>
class Node
{
private:
	Type value;
Node * pointers;//A reference to the array of nodes its connected to.
public:
	Node();
	Node(const Type& value);//use a constant reference.
	virtual ~Node();
	Type getValue();
	void setValue(const Type& value);
	Node * getPointers();

};

#endif /* SRC_MODEL_NODE_H_ */
