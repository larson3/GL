//todo

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	string inFile;
	string line;
	int test;
	inFile="CountriesContinents.txt";
	//inFile = inFile.c_str();
	
	ifstream fileName(inFile.c_str(), ios_base::in);
	
	while(getline(fileName,line))
	{
		
		char line2 = line[1];
		//cout<<line2<<endl;
		if(line2 < 96)
		{
			cout<<"Continent"<<endl;
		}
		//string line3 = line[1];
	
		//cout<<"Letter: "<<line[1]<<" Value: "<<test<<endl;
		
		//cout<<line<<endl;
	}
}