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
CTECBinaryTree<Type>::CTECBinaryTree()
{
    this->root = nullptr;
    this->size = 0;
    this->height = 0;
    this->balanced = true;
}

template <class Type>
CTECBinaryTree<Type>::~CTECBinaryTree()
{
    
}

template <class Type>
int CTECBinaryTree<Type>:: getSize()
{
    size = 0;
    calculateSize(root);
    return size;
    
}

template <class Type>
int CTECBinaryTree<Type>:: getHeight()
{
    
}

template <class Type>
void CTECBinaryTree<Type>:: calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getRightChild());
        size++;
    }
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRoot()
{
    return root;
}


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

template <class Type>
 bool CTECBinaryTree<Type>:: contains(Type value, TreeNode<Type> * currentTree)
{
    
    
    bool isInTree = false;
    if(currentTree != nullptr)
    {
        if(currentTree->getParent()->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            
            if(value < currentTree->getParent()->getValue())
            {
                isInTree = contains(value, currentTree->getParent()->getLeftChild());
            }
            
            else
            {
                isInTree = contains(value, currentTree->getParent()->getRightChild());
                
            }

        }
        
    }
    return isInTree;
    
}


template <class Type>
bool CTECBinaryTree<Type>:: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    
    else
    {
        TreeNode<Type> * current = root; //pointer to traverse the tree
        TreeNode<Type> * trailNode; //pointer behind current
        
        if(root == nullptr)
        {
            root = new TreeNode<Type>(value);
        }
        else
        {
            while (current != NULL)
            {
                trailNode = current;
                if (current->getValue() < value)
                {
                    current = current->getRightChild();
                }
                else
                {
                    current = current->getLeftChild();
                }
                
        }
            
            if(trailNode->getValue() > value)
            {
                TreeNode<Type> * insertNode = new TreeNode<Type>(value,trailNode);
                trailNode->setLeftChild(insertNode);
            }
        
        
    }
    
        return true;
    
    }//end insert
}


template <class Type>
void CTECBinaryTree<Type>:: remove(const Type& value)
{
    CTECBinaryTree<Type> * current;//pointer to traverse the tree
    CTECBinaryTree<Type> * trailCurrent; //pointer behind current
    CTECBinaryTree<Type> * temp; //pointer to delete the node
   
    if(!contains(value))
    {
        return;
    }
    else{
        current =root;
        trailCurrent = root;
        while(current != nullptr & current->getValue() != value)
        {
            trailCurrent = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        if(current == root)
        {
            remove(root);
        }
        else if(trailCurrent->getValue() > value)
        {
            remove(trailCurrent->getLeftChild());
        }
                   else
            {
                       remove(trailCurrent->getRightChild());
                   }
    }
    
    
}

template <class Type>
void CTECBinaryTree<Type>:: remove(TreeNode<Type> * nodeToBeRemoved)
{
    CTECBinaryTree<Type> * current;//pointer to traverse the tree
    CTECBinaryTree<Type> * trailCurrent; //pointer behind current
    CTECBinaryTree<Type> * temp; //pointer to delete the node
    if(nodeToBeRemoved == nullptr)
    {
        cerr << "" << endl;
    }
    else if(nodeToBeRemoved->getLeftChld() == nullptr &&
            nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nullptr;
        delete temp;
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getRighthild();
        delete temp;
    }
    else if(nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getLeftChild();
        delete temp;
    }
    else
    {
        current = nodeToBeRemoved->getLeftChild();
        trailCurrent = nullptr;
        
        while(current->getRightChild != nullptr)
        {
            trailCurrent = current;
            current = current->getRightChild();
        }
        nodeToBeRemoved->setValue(current->Value());//swap nodeToBeRemoved with bottom right child and then deletes
        if(trailCurrent == nullptr)
        {
            nodeToBeRemoved->setLeftChild(current->getLeftChild());
        }
        
        else
        {
            trailCurrent->setRightChild(current->getLeftChild());
        }
        delete current;
    }
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type>:: getRightMostChild(TreeNode<Type> leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree;
    
    while(rightNode->getRighthild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type>:: getLeftMostChild(TreeNode<Type> rightSubTree)
{
    
    TreeNode<Type> * leftNode = rightSubTree;
    while(leftNode->getRighthild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}






