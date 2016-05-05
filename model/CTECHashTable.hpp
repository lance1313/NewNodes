//
//  CTECHashTable.hpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

template <class Type>
class CTECHashable
{
private:
    
    int size;
    int capacity;
    Type * internalStorage;
    double efficiencyPercentage;
    int findPosition(const Type& value);
    int handleCollision(const Type& value);
    void updateSize()
    
    
public:
    CTECHashTable();
    ~CTECHashTable();
    
    void add(const Type& value);
    bool remove(const Type& value);
    bool contains(const Type& value);
    
    int getSize();
    
};

#endif /* CTECHashTable_hpp */
