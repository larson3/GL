#include <iostream>
#include <string>
#include <fstream>
#include "SeismicDataCollector.h"


using namespace std;
void printGreeting();
int main(int argc, char *argv[])
{
	string inFile;
	inFile=argv[1];
	printGreeting();
	SeismicDataCollector newFile;
	newFile.readFile(inFile);
}

void printGreeting()
{
	cout<<"John Larson, section 4"<<endl;
}