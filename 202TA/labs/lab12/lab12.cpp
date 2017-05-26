//lab12.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Implement a templated class named swapMin that compares two items.
//It can accept an int, char, double, float, or string.
//The parameters are value1 and value2. If value1 is less than value2, they swap.
//HINT: Use pass-by-reference for the templated class.

//Class Definition here!
template <class T>
void swapMin(T&value1, T&value2)
{
	vector<T>temp;
	cout<<"V1: "<<value1<<" V2: "<<value2<<endl;
	if(value1<value2)
	{
		temp.push_back(value1);
		value1=value2;
		value2 = temp[0];
		temp.pop_back();
	}
	cout<<"V1: "<<value1<<" V2: "<<value2<<endl;
}

int main () {
  int a1 = 5;
  int b1 = 10;
  char a2 = 'A';
  char b2 = 'F';
  double a3 = 5.3;
  double b3 = 15.1;
  string a4 = "candy";
  string b4 = "pizza";
  swapMin(a1,b1);
  swapMin(a2,b2);
  swapMin(a3,b3);
  swapMin(a4,b4);
  cout << "a1=" << a1 << " b1=" << b1 << endl;
  cout << "a2=" << a2 << " b2=" << b2 << endl;
  cout << "a3=" << a3 << " b3=" << b3 << endl;
  cout << "a4=" << a4 << " b4=" << b4 << endl;
  return 0;
}
