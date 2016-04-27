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
#include "../Model/CTECBinaryTree.cpp"

using namespace std;

class NodeController
{
private:
	CTECArray<int> * ints;
	CTECList<int> * numbers;
	Node<string> stringNode;
    void sortData();
    int * mergeData;
    void doMergesort();
    void mergesort(int data [], int size);
    void merge(int data [], int sizene, int sizeTwo);
    void quicksort(int place1, int place2);
    int partition(int place1, int place2);
    void swap(int place1, int place2);
    void doQuick();

	Node<int> intNode;
	ArrayNode<string> stringArrayNode;
	ArrayNode<string> otherArrayNode;
	Timer arrayTimer;
    
    void tryTree();
    void tryGraph();
public:
	NodeController();
	void start();
	virtual ~NodeController();
	void testLists();
};

#endif /* SRC_CONTROLLER_NODECONTROLLER_H_ */
