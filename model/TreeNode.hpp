//
//  TreeNode.hpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

#include "Node.h"
#include "TreeNode.hpp"

namespace CTECData
{
    template <class Type>
    class TreeNode : public Node<Type>
    {
    private:
        TreeNode<Type> * leftChild;
        TreeNode<Type> * rightChild;
        TreeNode<Type> * parent;
        
    public:
        TreeNode<Type>();
        TreeNode<Type>(const Type& value);
        TreeNode<Type>(const Type& value, TreeNode<Type> * parent);
        void setLeftChild(TreeNode<Type> * leftChild);
        void setRightChild(TreeNode<Type> * rightChild);
        void setParent(TreeNode<Type> * parent);
        
        TreeNode<Type> * geLeftChild();
        TreeNode<Type> * getRightChild();
        TreeNode<Type> * getParent();
        
    };
    
    
}


#endif /* TreeNode_hpp */
