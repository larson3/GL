#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "IntervalHeap.h"
using namespace std;

//prints username and section
void greeting()
{
	cout<<"John Larson, section 4"<<endl;
}

 //main method that calls appropriate methods to built the interval heap, iteraltively delete min-max from the interval heap and print results to the results.txt file 
int main(int argc, char * argv[])
{
	greeting();
	IntervalHeap iHeap(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
	//removing any remaining outfile info
	if( remove( "results.txt" ) != 0 )
	{
		cout<<"";
	}
	else
	{
		cout<<"";
	}
	
	//creating a new output object and writing to it
	ofstream outFile("results.txt", ios::app);
	outFile<<"min= "<<argv[1]<<" max= "<<argv[2]<<" size= "<<argv[3]<<" seed= "<<argv[4]<<endl;
	iHeap.insertRandomNumbers(outFile);
	iHeap.deleteMinMaxIteratively(outFile);
	outFile.close();
	return 0;
}