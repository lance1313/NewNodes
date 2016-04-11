//
//  CTECBinaryTree.hpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include <stdio.h>
#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    int size;
    TreeNode<Type> * root;
    int height;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    
public:
    
    CTECBinaryTree();
    ~CTECBinaryTree();
    int getSize();
    int getHeight();
    bool insert(const Type& value);
    Type remove(const Type& value);
    bool isBalanced();
    TreeNode<Type> * getRoot();
    
};



#endif /* CTECBinaryTree_hpp */