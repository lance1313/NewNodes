/*
 * NodeControllrer.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jlin3312
 */

#include "NodeController.h"
#include <stdlib.h>// allows accesss to rand() function for random #
#include <iostream>


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
}


NodeController::~NodeController()
{


}

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

void NodeController:: swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}


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


void NodeController :: sortData()
{
    /*
     Create a CtecList and array fill them with stuff(numbers)
     start timer , sort stop timer, display info for list
      start timer , sort stop timer, display info for array
     */
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
