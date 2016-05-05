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
    this->internalStora = new Type[capacity];
    
}

template <class Type>
CTECHashTable<Type>:: ~CTECHashTable()
{
    delete [] internalStorage;
}

template <class Type>
int CTECHashTable<Type>:: getSize()
{
    return this->size;
}

