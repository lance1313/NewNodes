//
//  CTECHashTable.cpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECHashTable.hpp"

#include<iostream>


using namespace std;

template <class Type>
 CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->internalStorage = new Type[capacity];
    
}
/*
 *deallocates all memory attched to the internal strogare.
 *
 */
template <class Type>
CTECHashTable<Type>:: ~CTECHashTable()
{
    delete [] internalStorage;
}

/*
*return the size of the structure
*
 */
 
 
template <class Type>
int CTECHashTable<Type>:: getSize()
{
    return this->size;
}

/*
 *Check if the val;ue exists in the table ifo
 *it will update the size if needed then find the place
 *for the item in the table. Then loop
 */
 
template <class Type>
void CTECHashTable<Type>:: add(const Type& value)
{
    if(!contains(value))
    {
        //resize if needed.
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        int insertionIndex = findPosition(value);
        
        if(internalStorage[insertionIndex] != nullptr)
        {
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
        }
        internalStorage[insertionIndex] = value;
        size++;
    }
}






