#include <iostream>
#include "BinarySearchTree.h"
#include "RandomBinarySearchTree.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>


using namespace std;

void printGreeting()
{
	cout<<"John Larson, section 4"<<endl;
}
   
int main(int argc, char *argv[])
{
	string rel;
	string line;
	stringstream ss;
	int fileLength;
	string inFile = argv[1];
	string length = argv[2];
    BinarySearchTree<int> t;
	RandomBinarySearchTree<int> rbst;

	//bringing in the data
	ifstream fileName(inFile.c_str(), ios_base::in);
	
	//and parsing for newline then whitespace
	while(getline(fileName, line, '\n'))
	{
		//counting the lines for use later
		fileLength++;
		istringstream ss(line);
		while(getline(ss,rel,' '))
		{
			int templine = atoi(rel.c_str());
			t.insert(templine);
			rbst.insert(templine);
		}
		
	}
	
	//i want to make sure there is some substance to the file
	if(fileLength==0)
	{
		cout<<"The file is empty or doesn't exist"<<endl;
		exit(0);
	}
	
	//we don't want to write on top of an old file
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
	
	outFile<<"Height of bst is: "<<t.height()<<endl;
	outFile<<"Height of rbst is: "<<rbst.height()<<endl;
	//level order handles the printing inside of the function
    outFile<<"Level order print of regular BST is "<<endl;
	t.levelOrder(atoi(length.c_str()),outFile);
	
	outFile<<"Level order print of Randomized BST is "<<endl;
	rbst.levelOrder(atoi(length.c_str()),outFile);

	printGreeting();
	outFile.close();
    return 0;
}
