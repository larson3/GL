#include <iostream>

using namespace std;

void drink(int &hp)
{
	hp+=2;
}

int main()
{
	char input[50];
	int hp = 10;
	cout<<"hp = "<<hp<<endl;
	cout<<"What do"<<endl;
	cin>>input;
	if(strcmpinput == "drink")
	{
		drink(hp);
	}
	else
	{
		cout<<"Wtf is that"<<endl;
	}
	cout<<hp<<endl;
	return 0;
}