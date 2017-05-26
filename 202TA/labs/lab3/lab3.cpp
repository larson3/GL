#include <iostream>

using namespace std;

int main()
{
	int numIcedTea = 10;
	int *ptrIcedTea;
	ptrIcedTea = &numIcedTea;
	
	cout<<ptrIcedTea<<endl;
	cout<<*ptrIcedTea<<endl;
	*ptrIcedTea+=10;
	cout<<numIcedTea<<endl;
	cout<<*ptrIcedTea<<endl;
	couut<<"Hello World"<<endl;
	return 0;
}