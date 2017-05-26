#include <iostream>

using namespace std;

int array1[5];

int main(){
  for(int i=0;i<5;i++){
    array1[i]=0;
    array1[i]++;
    cout<<array1[i]<<"\n";
  }
  return 0;
}
