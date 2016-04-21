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
    void calculateSize(TreeNode<Type> * currentNode);//Done
    bool contains(Type value, TreeNode<Type> * currentTree);//Done
    TreeNode<Type> * getRightMostChild(TreeNode<Type> leftSubTree);
    TreeNode<Type> * getLeftMostChild(TreeNode<Type> rightSubTree);
    void remove(TreeNode<Type> nodeToBeRemoved());
    
public:
    
    CTECBinaryTree();//Done
    ~CTECBinaryTree();
    int getSize();//Done
    int getHeight();
    bool contains(Type value);//Done
    bool insert(const Type& value);//Done
    void remove(const Type& value);
    bool isBalanced();
    TreeNode<Type> * getRoot();
    void preorderTraversal(TreeNode<Type> * currentTree);//Done
    void inorderTraversal(TreeNode<Type> * currentTree);//Done
    void postorderTraversal(TreeNode<Type> * currentTree);//Done
    
    
};



#endif /* CTECBinaryTree_hpp */
