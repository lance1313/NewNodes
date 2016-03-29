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

void NodeController :: testLists()
{
    numbers->addToFront(3);
    numbers->addToEnd(8);
    cout << "End should be 8 and is: " << numbers->getEnd() << endl;
    
    cout << "Head should be 3 and is: " << numbers->getFront() << endl;
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
