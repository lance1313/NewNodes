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
 bool CTECBinaryTree<Type>:: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    
    
    bool isInTree = false;
    if(currentTree != nullptr)
    {
        if(currentTree->getRoot()->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            
            if(value < currentTree->getRoot()->getValue())
            {
                isInTree = contains(value, currentTree->getRoot()->getLeftChild());
            }
            
            else
            {
                isInTree = contains(value, currentTree->getRoot()->getRightChild());
                
            }

        }
        return isInTree;
    }
    
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
        CTECBinaryTree<Type> * current = root; //pointer to traverse the tree
        CTECBinaryTree<Type> * trailNode; //pointer behind current
        
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
                trailNode->setLeftChild();
            }
        
        
    }
    
        return true;
    
    }//end insert
}


template <class Type>
Type CTECBinaryTree<Type>:: remove(const Type& value)
{
    CTECBinaryTree<Type> *current;//pointer to traverse the tree
    CTECBinaryTree<Type> *trailCurrent; //pointer behind current
    CTECBinaryTree<Type> *temp; //pointer to delete the node
    if (value == NULL)
        cerr << "Error: The node to be deleted is NULL." << endl;
    else if(value->getLeftChild == NULL && value->getRightChild == NULL)
    {
        temp = value;
        value = NULL;
        delete temp;
    }
    else if(value->getLeftChild == NULL)
    {
        temp = value;
        value = temp->getRightChild;
        delete temp;
    }
    else if(value->getRightChild == NULL)
    {
        temp = value;
        value = temp->getLeftChild;
        delete temp;
    }
    else
    {
        current = value->getLeftChild;
        trailCurrent = NULL;
        while (current->getRightChild != NULL)
        {
            trailCurrent = current;
            current = current->getRightChild;
        }//end while
        value->info = current->info;
        if (trailCurrent == NULL) //current did not move;
            //current == p->llink; adjust p
            value->getLeftChild = current->getLeftChild;
        else
            trailCurrent->getRightChild = current->getLeftChild;
        delete current;
    }//end else
    
    
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type>:: getRightMostChild(CTECBinaryTree<Type> leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    
    while(rightNode->getRighthild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type>:: getLeftMostChild(CTECBinaryTree<Type> rightSubTree)
{
    
    TreeNode<Type> * leftNode = rightSubTree->getRoot();
    while(leftNode->getRighthild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}






