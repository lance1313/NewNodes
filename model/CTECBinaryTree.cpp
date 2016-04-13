//
//  CTECBinaryTree.cpp
//  NewNodes
//
//  Created by Lindquist, Jacob on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.hpp"
using namespace std;

template <class Type>
 void CTECBinaryTree<Type>:: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout<< currentNode->getValue() << " ";
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
    }
    
}


template <class Type>
void CTECBinaryTree<Type>:: inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
       
        inorderTraversal(currentNode->getLeftChild());
         cout<< currentNode->getValue() << " ";
        inorderTraversal(currentNode->getRightChild());
    }
    
}

template <class Type>
void CTECBinaryTree<Type>:: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout<< currentNode->getValue() << " ";
    }
    
}

template <class Type>
bool CTECBinaryTree<Type>:: contains(Type value)
{
    bool isInTree = false;
    
    if(root != nullptr)
    {
        if(root->getValue() ==value)
        {
            isInTree = true;
        }
        
        else
        {
                if(value < root->getValue())
                {
                    isInTree = contains(value, root->getLeftChild());
                }
            
                else
                {
                    isInTree = contains(value, root->getRightChild());

                }
        }
    }
    
    
    return isInTree;
}