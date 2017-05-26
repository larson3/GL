#include <iostream>
#include <string>
#include <fstream>
#include "Calculate.h"


using namespace std;
void printGreeting();
int main(int argc, char *argv[])
{
	string inFile;
	inFile=argv[1];
	printGreeting();
	Calculate calc;
	calc.readFile(inFile);
	

	return 0;
}

void printGreeting()
{
	cout<<"John Larson, section 4"<<endl;
}