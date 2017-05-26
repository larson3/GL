#include <iostream>
#include "QuadraticProbing.h"
#include <dirent.h>
#include <sys/stat.h>
#include "ReadData.h"
#include "SoloHash.h"
#include <vector>

using namespace std;

void printGreeting();
    // Simple main
int main(int argc, char * argv[])
{
	printGreeting();


	ReadData plays;
	char const* strName = argv[1];
	plays.openDirectory(strName);
	plays.calculateJaccard();


    return 0;
}

void printGreeting()
{
	cout<<"John Larson, section 4"<<endl;
}