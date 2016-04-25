//
//  CTECGraph.hpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECGraph_hpp
#define CTECGraph_hpp

#include <stdio.h>
#include <set>


template <class Type>
class CTECGraph
{
private:
    static const int MAXIMUM = 20;
    bool adjecencyMatrix [MAXIMUM][MAXIMUM];
    Type labels[MAXIMUM];
    int manyVertices;
public:
    CTECGraph();
    ~CTECGraph();
    
    void addVertex(const Type& value);
    void addEdge(int source, int target);
    void remveEdge(int source,int taget);
    Type& operator [] (int vertex);//change value
    Type operator [] (int vertex) const;//copy value
    int size();
    bool isEdge(int source, int target);
    std::set<int> neighbors(int vertex) const;
};

#endif /* CTECGraph_hpp */
