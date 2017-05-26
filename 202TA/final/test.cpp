#include <iostream>


using namespace std;

int main()
{
  int array1[5];
  int array2[5];
  int *arrayPtr1, *arrayPtr2, *arrayPtr3;
  for(int x = 0;x<5;x++)
    {
      array1[x] = x*x;
      array2[x] = 10-x;
    }
  arrayPtr1 = array1 + 3;
  arrayPtr2 = arrayPtr1;
  arrayPtr2 = arrayPtr2 + 1;
  arrayPtr1-=1;
  arrayPtr3 = array2;
  *arrayPtr3+=*arrayPtr3;
  cout<<*arrayPtr1<<endl;
  cout<<*arrayPtr2<<endl;
  cout<<*arrayPtr3<<endl;
  
  return 0;
}
