//
//  TreeNode.cpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//


#include "TreeNode.hpp"


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
        this->rightChild = nullptr;
        this->parent = nullptr;
        
        this->setValue(value);
        
    }
    
    template <class Type>
    TreeNode<Type> :: TreeNode(const Type& value, TreeNode<Type> * parent) : Node<Type>(value)
    {
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->parent = parent;
    }
    
// method used in all TreeNode strutures
    template <class Type>
    void TreeNode<Type> :: setLeftChild(TreeNode<Type> * leftChild)
    {
        this->leftChild = leftChild;
    }
    // method used in all TreeNode strutures
    template <class Type>
    void TreeNode<Type> :: setRightChild(TreeNode<Type> * rightChild)
    {
        this->rightChild = rightChild;
    }
    
    // method used in all TreeNode strutures
    template <class Type>
    void TreeNode<Type> :: setParent(TreeNode<Type> * parent)
    {
        parent->value;
    }
    // method used in all TreeNode strutures
    template <class Type>
    TreeNode<Type> * TreeNode<Type>:: getLeftChild()
    {
        return leftChild;
    }
    // method used in all TreeNode strutures
    template <class Type>
    TreeNode<Type> *  TreeNode<Type>:: getRightChild()
    {
        return rightChild;
    }
    // method used in all TreeNode strutures
    template <class Type>
    TreeNode<Type> *
TreeNode<Type> :: getParent()
    {
        return parent;
    }
    




