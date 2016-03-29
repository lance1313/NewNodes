/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: jlin3312
 */

#ifndef SRC_MODEL_CTECARRAY_H_
#define SRC_MODEL_CTECARRAY_H_
#include "ArrayNode.h"

template <class Type>
class CTECArray
{
private:
	int size;
	ArrayNode<Type> * head;

public:
	CTECArray();
    int indexOf(Type searchValue);
    int nextIndexOf(int startingIndex,Type searchValue);
    void swap(int indexOne, int indexTwo);

	virtual ~CTECArray();
	int getSize();
	void set(int position,const Type& value);
	Type get(int position);
	CTECArray(int size);
    void selectionSort();
};

#endif /* SRC_MODEL_CTECARRAY_H_ */
