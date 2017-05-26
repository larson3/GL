#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int MAX_SIZE=10;
const int MIN_SIZE=4;
char board[MAX_SIZE][MAX_SIZE];
int boardSize;
char*dash="-";
int turnCount=0;
char playerSymbol;
int col;
int row;
bool legalMove;


void printBoard(char board[][MAX_SIZE],int MAX_SIZE,int boardSize);
char whichPlayer(int turnCount);
void GetNextMove(char playerSymbol,int &row, int &col);
bool validMove(char playerSymbol, int row, int col, int boardSize,char board[][MAX_SIZE],int MAX_SIZE);
void updateBoard(char (&board)[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol,int boardSize);
void checkUp(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE,int row, int col, char playerSymbol, int boardSize);


void printBoard(char board[][MAX_SIZE], int MAX_SIZE,int boardSize){
  for(int count=0; count<boardSize;count++)
    {

      for(int count1=0;count1<boardSize;count1++)
        {
          cout<<board[count][count1];
        }
      cout<<"\n";
    }
}
 
char whichPlayer(int turnCount){
  if (turnCount%2==0){
    playerSymbol='X';
  }
  else{
    playerSymbol='O';
  }
  turnCount++;
  return playerSymbol;
}

//Prompting the player for a move and passing the value by reference
void GetNextMove(char playerSymbol, int &row, int &col){
  cout<<"Player " << playerSymbol << " 's move: ";
  cin>>row>>col;
}

//checking to see if the move is allowed
bool validMove(char playerSymbol, int row, int col, int boardSize,char board[][MAX_SIZE],int MAX_SIZE)
{
  if (col>boardSize || col<=0 || row>boardSize || row<=0)
    {
      cout<<"\""<<row<<" "<<col<<"\""<<" is out of bounds!"<<"\n";
      return false;
    }
  else if (board[row-1][col-1]=='X' || board[row-1][col-1]=='O'){
    cout<<"\""<<row<<" "<<col<<"\""<<" has already been used!"<<"\n";
    return false;
  }
  else{
    return true;
  }
}

void updateBoard(char (&board)[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char  playerSymbol,int boardSize){
  board[row-1][col-1]=playerSymbol;
  
}

void checkUp(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE,int row, int col, char playerSymbol, int boardSize)
{
  int rowCount=1;
  bool boundsCheck=true;
  char oppSymbol;
  if (playerSymbol=='X'){
    oppSymbol='O';
  }
  else
    {
      oppSymbol='X';
    }
  while (boundsCheck){
    if (board[row-rowCount][col]=='-' || row-rowCount<0){
      boundsCheck=false;
      
      //cout<<board[row-rowCount][col];
    }
    else if(board[row-rowCount][col]==playerSymbol){
      while(rowCount<row){
        board[row-rowCount][col]=playerSymbol;
        rowCount++;
	//cout<<"We are hitting playerSymbol";
      }
      boundsCheck=false;
    } 
    else if (board[row-rowCount][col]==oppSymbol){
      rowCount--;
      //cout<<"hitting opp";
    }
    else
      {
	boundsCheck=false;
	//cout<<"We are hitting else";
      }
  }  
}
