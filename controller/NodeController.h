/*
 * NodeControllrer.h
 *
 *  Created on: Jan 27, 2016
 *      Author: jlin3312
 */

#ifndef SRC_CONTROLLER_NODECONTROLLER_H_
#define SRC_CONTROLLER_NODECONTROLLER_H_
#include <string>
#include "../model/Node.cpp"
#include "../model/Node.h"
#include "../model/ArrayNode.cpp"
#include "../model/CTECArray.cpp"
#include "../model/ArrayNode.h"
#include "../model/Timer.h"
#include "../model/CTECList.h"
#include "../model/CTECList.cpp"

using namespace std;

class NodeController
{
private:
	CTECArray<int> * ints;
	//CTECList<int> * numbers;
	Node<string> stringNode;

	Node<int> intNode;
	ArrayNode<string> stringArrayNode;
	ArrayNode<string> otherArrayNode;
	Timer arrayTimer;
public:
	NodeController();
	void start();
	virtual ~NodeController();
	void testLists();
};

#endif /* SRC_CONTROLLER_NODECONTROLLER_H_ */
