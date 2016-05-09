//
//  CTECHashTable.hpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp
#include "HashNode.cpp"


template <class Type>
class CTECHashTable
{
private:
    
    int size;
    int capacity;
    HashNode<Type> * internalStorage;
    double efficiencyPercentage;
    int findPosition(HashNode<Type> value);
    int handleCollision(HashNode<Type> value);
    void updateCapacity();
    
    int getNextPrime();
    bool isPrime(int candidateNumber);
    
public:
    CTECHashTable();
    ~CTECHashTable();
    
    
    
    void add(HashNode<Type> value);
    bool remove(HashNode<Type> value);
    bool contains(HashNode<Type> value);
    
    int getSize();
    
};

#endif /* CTECHashTable_hpp */
