#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const int number=10;
int count=0;
int count1=0;
char board[number][number];
int main(){
char*dash="-";

 void printBoard(int count, char board[][number],int number);

//Beginning to create multidimensional array
for(int count=0; count<number;count++)
  {
    for(int count1=0;count1<number;count1++)
      {
	//populating board with dashes
	board[count][count1]=*dash;
      }
  }   
 printBoard(count, board,number);
 return 0;
}


void printBoard(int count,char board[][number], int number){
 for(int count=0; count<number;count++)
   {
     for(int count1=0;count1<number;count1++)
       {
	 cout<<board[count][count1];
       }
     cout<<"\n";
   }
}
