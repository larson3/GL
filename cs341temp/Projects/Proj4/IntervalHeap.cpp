#include <stdlib.h>
#include <iostream>
#include "IntervalHeap.h"
using namespace std;

IntervalHeap::IntervalHeap(){}

//Constructor
IntervalHeap::IntervalHeap(int min, int max, int inpSize, int inpSeed){
	
	inputSize = inpSize;
	minRange = min;
	maxRange = max;
	seed = inpSeed;
	srand(seed);
	currentSize = 0;
	heap = new LeftRightElements[inputSize];
	
}

//Destructor
IntervalHeap::~IntervalHeap(){
	delete[]heap;
}

//returns min from interval heap
int IntervalHeap::getMin(){
	return heap[1].left;
}

//returns max from interval heap
int IntervalHeap::getMax(){
	return heap[1].right;
}

//returns total number of elements in the interval heap 
int IntervalHeap::getSize(){
	return currentSize;
}

//method that generates random numbers and inserts them in the interval heap
void IntervalHeap::insertRandomNumbers(ostream &out){

	for(int i=0;i<inputSize;i++)
	{
		int nextNum = (rand()%(maxRange-minRange))+minRange;
		insert(nextNum);
	}
	out<<"Interval Heap built: "<<endl<<endl;
	printHeap(inputSize,out);
	out<<"\n";
}

//method that inserts an element into the interval heap
void IntervalHeap::insert(int n){
	//
	if(currentSize<2)
	{
		//our heap is empty, we need values for the first node
		if(currentSize == 0)
		{
			heap[1].left = n;
			heap[1].right = n;
		}
		//heap has one half-full node, changing right side.
		else
		{
			heap[1].right = n;
			if(heap[1].left>heap[1].right)
			{
				//we swap to preserve the intervalHeap structure
				swap(heap[1].left,heap[1].right);
			}
			
		}
		currentSize++;
	}
	//we already have at least a node
	else{
		//this is the last node in our array
		bool minSide;
		int lastNode = (currentSize/2) + currentSize%2;

		//if the num of nodes is odd we have a solo num in left
		if(currentSize%2 == 1)
		{
			//we're going to have to swap if the left is larger
			//than the right, but let's save that for later
			if(heap[lastNode].left > n)
			{
				minSide = true;
			}
			//otherwise it belongs in the right and we will compare
			//with its parents right value
			else
			{
				minSide = false;
			}
		}
		//we already have a full node so we look to the next
		else
		{
			lastNode++;

			//checking against parent
			if(n<heap[lastNode/2].left)
			{
				minSide = true;
			}
			else
			{
				minSide = false;
			}
		}
		//now we percolate if necessary
		if(minSide == true)
		{
			int oneUp = lastNode;
			while(oneUp>1 and n<heap[oneUp/2].left)
			{
				heap[oneUp].left = heap[oneUp/2].left;
				oneUp/=2;
			}
			heap[oneUp].left=n;
			currentSize++;
			if(currentSize%2 == 1)
			{
				heap[lastNode].right = heap[lastNode].left;
			}
			
		}
		else
		{
			int oneUp = lastNode;
			while(oneUp>1 and n>heap[oneUp/2].right)
			{
				heap[oneUp].right = heap[oneUp/2].right;
				oneUp/=2;
			}
				heap[oneUp].right = n;
				

			currentSize++;
			if(currentSize%2 == 1)
			{
				heap[lastNode].left = heap[lastNode].right;
			}
		}
	}
}


//method that deletes min and max ieratively until just element is left
void IntervalHeap::deleteMinMaxIteratively(ostream &out){
	int count = 0;
	//deleting until there's only one element
	while(currentSize>1)
	{
		//we always start with deleteMin
		if(count%2==0)
		{
			out<<"After deleting min element "<<getMin()<<endl<<endl;
			deleteMin();
		}
		else
		{
				
			out<<"After deleting max element "<<getMax()<<endl<<endl;
			deleteMax();
		}
		currentSize--;
		count++;
		printHeap(currentSize,out);
		out<<"\n";
	}
}

//method that deletes min from the interval heap
void IntervalHeap::deleteMin()
{
	
	int parentNode=1;
	int lastNode = (currentSize/2)+currentSize%2;
	//performing the initial swap of root and leaf
	heap[parentNode].left = heap[lastNode].left;
	//then we percolate until the heap is restored
	while(parentNode*2<=lastNode)
	{
		//checking to see if either child warrants switching
		if(heap[parentNode].left>heap[parentNode*2].left or heap[parentNode].left>heap[(parentNode*2)+1].left)
		{
			//comparing two two children and swapping the appropriate one
			if(heap[parentNode*2].left<=heap[(parentNode*2)+1].left)
			{
	
				swap(heap[parentNode].left,heap[parentNode*2].left);
				
				if(heap[parentNode*2].left>heap[parentNode*2].right)
				{
					swap(heap[parentNode*2].left,heap[parentNode*2].right);
				}
			//continuing down the heap
			parentNode*=2;
			}
			else
			{
				swap(heap[parentNode].left,heap[(parentNode*2)+1].left);
	
				if(heap[(parentNode*2)+1].left>heap[(parentNode*2)+1].right)
				{
					swap(heap[(parentNode*2)+1].left,heap[(parentNode*2)+1].right);
				}
				//continue down the right side of the heap
				parentNode*=2;
				parentNode++;
			}
		}
		else
		{
			//nothing needed to happen, still going down the heap
				parentNode*=2;
		}
		
	}
}

//method that deletes max from the interval heap
void IntervalHeap::deleteMax()
{

	int parentNode=1;
	int lastNode = (currentSize/2)+currentSize%2;
	heap[1].right = heap[lastNode].right;
	heap[lastNode].right=heap[lastNode].left;
	while(parentNode*2<=lastNode)
	{
		//this is the same as above, we check the children
		//the only difference is that now we are looking on the right side
		if(heap[parentNode].right<heap[parentNode*2].right or heap[parentNode].right<heap[(parentNode*2)+1].right)
		{
			if(heap[parentNode*2].right>=heap[(parentNode*2)+1].right)
			{
				swap(heap[parentNode].right,heap[parentNode*2].right);
			
				if(heap[parentNode*2].right<heap[parentNode*2].left)
				{
					swap(heap[parentNode*2].right,heap[parentNode*2].left);
				}
			
			parentNode*=2;
			}
			else
			{
				swap(heap[parentNode].right,heap[(parentNode*2)+1].right);
				
				if(heap[(parentNode*2)+1].right<heap[(parentNode*2)+1].left)
				{
					swap(heap[(parentNode*2)+1].right,heap[(parentNode*2)+1].left);
				}
				
				parentNode*=2;
				parentNode++;
			}
		}
		else
		{
				parentNode*=2;
		}
		
	}
}

void IntervalHeap::printHeap(int size,ostream &out)
{
	int x = 1;
	//needs to be done differently for even and odd sizes
	if(size%2==0)
	{
		for(x=1;x<=size/2;x++)
		{
			out<<heap[x].left<<","<<heap[x].right<<endl;
		}
	}
	else
	{
		//when the size is odd, there is one remaining item
		while(x<=size/2)
		{
			out<<heap[x].left<<","<<heap[x].right<<endl;
			x++;
		}
		//and it is printed alone right here
		out<<heap[x].right<<endl;
	}
}

