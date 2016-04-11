//
//  TreeNode.cpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "Node.h"
#include "TreeNode.hpp"

namespace CTECData
{
    template <class Type>
    TreeNode<Type> :: TreeNode() : Node<Type>()
    {
        this->leftChild = nullptr;
        this->righthild = nullptr;
        this->parent = nullptr;
    }
    
    template <class Type>
    TreeNode<Type> :: TreeNode(const Type& value) : Node<Type>(value)
    {
        this->leftChild = nullptr;
        this->righthild = nullptr;
        this->parent = nullptr;
        
        this->setValue(value);
        
    }
    
    template <class Type>
    TreeNode<Type> :: TreeNode(const Type& value, TreeNode<Type> * parent) : Node<Type>(value)
    {
        this->leftChild = nullptr;
        this->righthild = nullptr;
        this->parent = parent;
    }
    
}



