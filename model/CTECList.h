/*
 * CTECList.h
 *
 *  Created on: Feb 18, 2016
 *      Author: jlin3312
 */

#ifndef SRC_MODEL_CTECLIST_H_
#define SRC_MODEL_CTECLIST_H_
#include "ArrayNode.h"
//#include "../model/NodeController.h"

template <class Type>
class CTECList
{
private:
int size;
ArrayNode<Type> * head;
ArrayNode<Type> * tail;


public:
	CTECList();
	int setSize();
	Type getFromIndex(int index);
	Type getFront();
	Type getEnd();
	Type set(int index, const Type& value);
	Type removeFromFront();
	Type removeFromEnd();
	Type removeFromIndex(int index);
	void addToFront(const Type& value);
	void addToEnd();
	void addToIndex(int index,const Type& value);
	void calculateSize();
	//void add();
	virtual ~CTECList();
};

#endif /* SRC_MODEL_CTECLIST_H_ */
