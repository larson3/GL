#include <iostream>
#include <set>
using namespace std;
int main()
{
set <int> mySet;

mySet.insert(1);
mySet.insert(4);
mySet.insert(2);

set<int>::iterator pos;

for(pos = mySet.begin(); pos!= mySet.end(); pos++)
{
	cout<<*pos<<endl;
}

	return 0;
}