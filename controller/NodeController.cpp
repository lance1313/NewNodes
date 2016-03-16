/*
 * NodeControllrer.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jlin3312
 */

#include "NodeController.h"

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
	//numbers = new CTECList<int>();

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
	//numbers->addToFront(3);
	//numbers->addToEnd();
	//cout << "the test is to find end." << numbers->getFromIndex();
}
