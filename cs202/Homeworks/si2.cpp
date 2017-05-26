#include <iostream>;

using namespace std;

const int MAX_SIZE=10;

char array[MAX_SIZE][MAX_SIZE];
int i;
int j;
int main(){
  for (i=0;i<MAX_SIZE;i++){
    for (j=0;j<MAX_SIZE;j++){
      array[i][j]='+';
  }
}

for (i=0;i<MAX_SIZE;i++){
  for (j=0;j<MAX_SIZE;j++){
  cout<<array[i][j];
}
  cout<<endl;
}
 return 0;
}

