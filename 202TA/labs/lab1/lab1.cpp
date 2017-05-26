#include <iostream>
using namespace std;

int main(){
  int num;
  char bottle[80];
  
  cout << "What number would you like to start with? : " << endl;
  cin >> num;
  cout << "What type of bottle would you like to use? " << endl;
  if(cin.peek()=='\n')
  {
	cin.ignore();
  }
  cin.getline(bottle,80);
  cout << "Enter your last name: " << endl;
  while(num>0)
  {
	cout<<num<<" bottles of "<<bottle<<" on the wall."<<endl;
	cout<<num<<" bottles of "<<bottle<<endl;
	cout<<"Take one down, pass it around"<<endl;
	num--;
	cout<<num<<" bottles of "<<bottle<<" on the wall."<<endl;
  }
  return 0;
}
