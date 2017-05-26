#ifndef INTERVAL_HEAP_H
#define INTERVAL_HEAP_H

#include <fstream>
#include <iostream>
using namespace std;

class LeftRightElements {

public:
	int left;
	int right;
};



class IntervalHeap{
private:
	int currentSize;/*total number of elements in the interval heap*/
	LeftRightElements *heap;/*array to maintain heap structure*/
	int inputSize;/*the one that is provided with make run command*/
	int minRange;/*the one that is provided with make run command*/
	int maxRange;/*the one that is provided with make run command*/
	int seed;/*the one that is provided with make run command*/

public:

/****************************************************************
 * IntervalHeap():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
	IntervalHeap();

/****************************************************************
 * IntervalHeap(int,int,int,int):
 * Preconditions: 
 *	  requires four int primitives
 * Postconditions:
 *   Creates an object of type interval Heap
 ****************************************************************/
	IntervalHeap(int min, int max, int size, int seed);
	
/****************************************************************
 * ~IntervalHeap():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base destructor
 ****************************************************************/
	~IntervalHeap();
	
/****************************************************************
 * getMin():
 * Preconditions: 
 *	  valid interval heap
 * Postconditions:
 *   Returns the int stored in heap[1].left
 ****************************************************************/
	int getMin();
	
/****************************************************************
 * getMax():
 * Preconditions: 
 *	  valid interval heap
 * Postconditions:
 *   Returns the int stored in heap[1].right
 ****************************************************************/
	int getMax();
	
/****************************************************************
 * getSize():
 * Preconditions: 
 *	  valid interval heap
 * Postconditions:
 *   Returns the size of the current interval heap
 ****************************************************************/
	int getSize();
	
/****************************************************************
 * insertRandomNumbers(ostream & ):
 * Preconditions: 
 *	  valid interval heap and output object
 * Postconditions:
 *   Does a lot.  Will construct the heap with a select amount of
 *	 random numbers.  Will then write the completed heap to an outFile
 ****************************************************************/
	void insertRandomNumbers(ostream & out);
	
/****************************************************************
 * insert(int):
 * Preconditions: 
 *	  valid int
 * Postconditions:
 *   This method is called by insertRandomNumbers and will place
 *   a new int at the last open spot in the heap.  Will then heapify
 *	 and preserve the heap structure with some swapping.
 ****************************************************************/
	void insert(int element);
	
/****************************************************************
 * deleteMinMaxIteratively(ostream &):
 * Preconditions: 
 *	  valid heap and ostream object
 * Postconditions:
 *   will delete the entire heap one at a time, going min, max,min,max etc
 *	 Will heapify after each deletion to preserve heap structure.
 ****************************************************************/
	void deleteMinMaxIteratively(ostream &out);
	
/****************************************************************
 * deleteMin():
 * Preconditions: 
 *	  valid heap
 * Postconditions:
 *   Will swap the last element in the heaps' left object with the min.
 *	 Will then delete the min and heapify
 ****************************************************************/
	void deleteMin();
	
/****************************************************************
 * deleteMax():
 * Preconditions: 
 *	  valid heap
 * Postconditions:
 *   Will swap the last element in the heaps' right object with the max.
 *	 Will then delete the max and heapify
 ****************************************************************/
	void deleteMax();
	
/****************************************************************
 * printHeap(int, ostream&):
 * Preconditions: 
 *	  valid int and ostream obj
 * Postconditions:
 *   Will write the contents of the heap to an outFile.  This method
 *	 is a little different for an odd size, so that it can print the
 *	 last line with one item.
 ****************************************************************/
	void printHeap(int size, ostream &out);
};

#endif