/*
 * NodeControllrer.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jlin3312
 */

#include "NodeController.h"
#include <stdlib.h>// allows accesss to rand() function for random #
#include <iostream>
#include "../Model/CTECGraph.hpp"


using namespace std;
/**construtor to initialize variables
 *
 */
NodeController::NodeController()
{
	stringNode.setValue("asdf");
	intNode.setValue(99);
	ints = new CTECArray<int>(5);
	numbers = new CTECList<int>();

	stringArrayNode.setValue("Words in here");
	otherArrayNode.setValue("linked node");
	stringArrayNode.setNext(&otherArrayNode);

}
/**
 *this method does a recursion to display either fibonacci number or a factorial.
 */
void NodeController :: start()
{
	arrayTimer.startTimer();
	for(int index = 0; index < ints->getSize(); index++)
	{
		ints->set(index, (index *23));
	}
	for(int index =ints->getSize()-1; index >= 0; index--)
	{
		cout << "the contents of ints is " << index << " are: " << ints->get(index) << endl;
	}
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
    //tryGraph();
    testHashTable();
}


NodeController::~NodeController()
{


}
/**
 this is the method to try out  binary tree class.
 
 */
void NodeController:: tryTree()
{
    CTECBinaryTree<int> firstTree;
    firstTree.insert(13);
    firstTree.insert(-42);
    firstTree.insert(3);
    firstTree.insert(846);
    
    cout << "check contains" << endl;
    cout << firstTree.contains(3.5) << endl;
    
    cout <<"Let's look at the tree." << endl;
    firstTree.inorderTraversal(firstTree.getRoot());
    cout <<"\nLet's look at the tree." << endl;
    firstTree.preorderTraversal(firstTree.getRoot());
    cout <<"\nLet's look at the tree." << endl;
    firstTree.postorderTraversal(firstTree.getRoot());
}

void NodeController::testHashTable()
{
    CTECHashTable<int> tempTable;
    HashNode<int> tempArray[10];
    for(int spot = 0; spot < 10; spot++)
    {
        int randomValue  = rand();
        int randomKey = rand();
        int randomValue2  = rand();
        int randomKey2 = rand();
        
        int randomValue3  = rand();
        int randomKey3 = rand();
        int randomValue4  = rand();
        int randomKey4 = rand();
        HashNode<int> temp = HashNode<int>(randomKey, randomValue);
        HashNode<int> temp2 = HashNode<int>(randomKey2, randomValue2);
        HashNode<int> temp3 = HashNode<int>(randomKey3, randomValue3);
        HashNode<int> temp4 = HashNode<int>(randomKey4, randomValue4);
        tempTable.add(temp);
        tempTable.add(temp2);
        tempTable.add(temp3);
        tempTable.add(temp4);
        tempArray[spot] = temp;
    }
    //tempTable.add(0);
    bool test = tempTable.contains(tempArray[9]);
    tempTable.contains(tempArray[1]);
    tempTable.contains(tempArray[5]);
    tempTable.contains(tempArray[8]);
    tempTable.contains(tempArray[6]);
     tempTable.contains(tempArray[2]);
    string result;
    if(test)
    {
        result = "It's in the hash table!";
    }
    else
    {
        result = "Can't find value:(";
    }
    cout << result << endl;
}
/*
 method to try out graph struture
 
 */
void NodeController::tryGraph()
{
    CTECGraph<int> testGraph;
    
    testGraph.addVertex(7);
    testGraph.addVertex(8);
    testGraph.addVertex(9);
    testGraph.addVertex(78);
    testGraph.addVertex(87);
    testGraph.addVertex(74);
    testGraph.addVertex(722);
    testGraph.addVertex(713);
    testGraph.addVertex(70);
    testGraph.addVertex(90);
    
    testGraph.depthFirstTraversal(testGraph, 0);
    
    testGraph.breadthFirstTraversal(testGraph, 0);
}
/*
 
 method with actual code helers are merge and merge sort
 */
void NodeController:: doMergesort()
{
    mergeData = new int[500000];
    
    for(int spot = 0; spot < 50000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 500000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    for(int spot = 0; spot < 5000; spot++)
    {
         cout << mergeData[spot] << ", ";
    }
    delete [] mergeData;
    
}


/*
 method to  run the merge sort on arrays
 */
void NodeController:: mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        
        mergesort(data, sizeOne);
        mergesort((data+sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
        
        
        
    }
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while ((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne) [copied2])//smaller goes in small half
        {
            temp[copied++] = data[copied1++];
        }
        else{// large  goes in large half
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    
    while (copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    
    while (copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2];
    }
    for(index = 0; index < sizeOne+ sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController :: testLists()
{
    
    numbers->addToFront(3);
    numbers->addToEnd(8);
    cout << "End should be 8 and is: " << numbers->getEnd() << endl;
    
    cout << "Head should be 3 and is: " << numbers->getFront() << endl;
}
//method for quick sorting any array.
void NodeController::quicksort(int first, int last)
{
    int pivotIndex;
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex-1);
        quicksort(pivotIndex+1, last);
    }
}
// use to put space for array.
int NodeController::partition(int first, int last)
{
    
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index =first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    
    swap(first, smallIndex);
    return smallIndex;
    
}
//used to swap data
void NodeController:: swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

//used to help quick sort
void NodeController:: doQuick()
{
    mergeData = new int[1000000000];
    
    for(int spot = 0; spot < 1000000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
        
    }
    
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 500000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
    
    
}

/*
 Create a CtecList and array fill them with stuff(numbers)
 start timer , sort stop timer, display info for list
 start timer , sort stop timer, display info for array
 */
void NodeController :: sortData()
{
    
    CTECArray<int> randomNumberArray(5000);
    CTECList<int> randomNumberList;
    int myCPlusPlusArray[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        randomNumberArray.set(spot, myRandom);
        randomNumberList.addToEnd(myRandom);
        myCPlusPlusArray[spot] = myRandom;
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    randomNumberArray.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    
    sortTimer.startTimer();
    std::sort(std::begin(myCPlusPlusArray), std::end(myCPlusPlusArray));
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    
}
