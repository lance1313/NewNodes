//
//  HashNode.cpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashNode.hpp"
using namespace CTECData;

template <class Type>
HashNode<Type>:: HashNode(int key, const Type& value)
{
    this->key = key;
     this->value = value;
}

template <class Type>
int HashNode<Type>:: getKey()
{
    return key;
}

template <class Type>
Type HashNode<Type> :: getValue()
{
    return value;
}
