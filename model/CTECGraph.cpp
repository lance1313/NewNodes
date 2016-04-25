//
//  CTECGraph.cpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECGraph.hpp"


template <class Type>
const int  CTECGraph<Type> :: MAXIMUM;

template <class Type>
void CTECGraph<Type>:: addVertex(const Type& value)
{
    assert(size() < MAXIMUM);
    int newVertexNumber = manyVertices;
    manyVertices++;
    for(int otherVertexNumber = 0; otherVertexNumber < manyVertices; otherVertexNumber++)
    {
        adjecencyMatrix[otherVertexNumber] [newVertexNumber] = false;
         adjecencyMatrix[newVertexNumber] [otherVertexNumber] = false;
        
    }
    labels[newVertexNumber] = value;
    
}

template <class Type>
void CTECGraph<Type>:: addEdge(int source, int target)
{
    assert(source < size() && target< size());
    adjecencyMatrix[source][target] = true;
}

template <class Type>
bool CTECGraph<Type>:: isEdge(int source, int target) const
{
    assert(source < size() && target< size());
    bool isAnEdge = false;
    isAnEdge = adjecencyMatrix[source][target];
    
    return isAnEdge;
}


