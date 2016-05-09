//
//  CTECHashTable.cpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECHashTable.hpp"
#include <cmath>
#include<iostream>


using namespace std;

template <class Type>
 CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->internalStorage = new HashNode<Type>[capacity];
    
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
void CTECHashTable<Type>:: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        //resize if needed.
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateCapacity();
        }
        int insertionIndex = findPosition(currentNode);
        
        if(internalStorage[insertionIndex] != nullptr)
        {
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
        }
        internalStorage[insertionIndex] = currentNode;
        size++;
    }
}

/*
 *finds the simplest hash for thr associated key pair.
 *using modulo of the key by the capacity.
 */
 

template <class Type>
int CTECHashTable<Type>:: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode->getKey % capacity;
    
    
    return  position;
    
}

template <class Type>
int CTECHashTable<Type>:: getNextPrime()
{
    int nextPrime = capacity;
    
    nextPrime *= 2;
    nextPrime++;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    
    return nextPrime;
}

template <class Type>
bool CTECHashTable<Type>:: isPrime(int candidateNumber)
{
    bool isPrime = false;
    
    if(candidateNumber <= 1)
    {
        isPrime = false;
    }
    else if (candidateNumber == 2 || candidateNumber ==3)
    {
        isPrime = true;
    }
    
    else if (candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    
    else
    {
        for(int spot = 3; spot < sqrt(candidateNumber) + 1; spot +=2 )
        {
            if(candidateNumber % spot == 0)
            {
                isPrime =false;
                break;
            }
        }
    }
    
    return isPrime;
}


template <class Type>
void CTECHashTable<Type>:: updateCapacity()
{
    int updatedCapacity = getNextPrime();
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    HashNode<Type> * largerStorage = new HashNode<Type>[capacity];
    
    for(int index =0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedIndex = findPosition(internalStorage[index]);
            largerStorage[updatedIndex] = internalStorage[index];
        }
        
    }
    
    internalStorage = largerStorage;
    
    
    
}

template <class Type>
bool CTECHashTable<Type>:: remove(HashNode<Type> currentNode)
{
    
}

template <class Type>
bool CTECHashTable<Type>:: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    int possibleLocation = findPosition(currentNode);
    
    while(internalStorage[possibleLocation] != nullptr && !isInTable)
    {
        if(internalStorage[possibleLocation].getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        possibleLocation = (possibleLocation) + 1 % capacity;
    }
    
    return  isInTable;
}
