/*****************************************
 ** File:    Proj1.cpp
 ** Project: CMSC 202 Project 1, Fall 2014
 ** Author:  John Larson
 ** Date:    10/1/2014
 ** Section: 7
 ** E-mail:  larson3@umbc.edu
 **
 **   This file contains the main driver program for Project 1.
 ** This file will create a 2D array and play a game of 'reversi' with
 ** the user.  It will take in coordinates from the user and place them on
 ** the board.  It will then check for squares nearby and perform a flip
 ** on any opponent's squares which the player is surrounding.  At the 
 ** the game will add up the scores and exit.
 ***********************************************/


#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "proj1Aux.h"
using namespace std;




char board[MAX_SIZE][MAX_SIZE];
int boardSize;
char*dash="-";
int turnCount=0;
char playerSymbol;
int col;
int row;
bool legalMove;
int xCount;
int oCount;




int main(int argc, char* argv[]){
  //converting input into an int
  int boardSize=atoi(argv[1]);
  int totalSquares=boardSize*boardSize;
  //checking to make sure that board is even and between 4 and 10
  if (boardSize >=MIN_SIZE && boardSize<=MAX_SIZE && boardSize%2==0){
    cout<<"Welcome to Reversi!"<<"\n";

    //Beginning to create multidimensional array
    for(int count=0; count<boardSize;count++)
      {
	for(int count1=0;count1<boardSize;count1++)
	  {
	    //populating board with dashes
	    board[count][count1]=*dash;
	  }
      }
    //main game loop
    while (turnCount<totalSquares){
      legalMove=false;
      
      playerSymbol=whichPlayer(turnCount);
      //starting a loop to reprompt if invalid input
      while(legalMove==false){

	//getting the user's coordinates
	GetNextMove(playerSymbol,row,col);
	//checking the validity of the move
	legalMove=validMove(playerSymbol,row,col,boardSize,board,MAX_SIZE);
      }
	updateBoard(board, MAX_SIZE, row-1, col-1, playerSymbol, boardSize);
	//running checks to see if we need to flip, then flipping
	checkBoardRight(board,MAX_SIZE,row-1,col-1,playerSymbol);

	checkBoardLeft(board,MAX_SIZE,row-1,col-1,playerSymbol);

	checkBoardUp(board,MAX_SIZE,row-1,col-1,playerSymbol);

	checkBoardDown(board,MAX_SIZE,row-1,col-1,playerSymbol);

	checkBoardUpRight(board,MAX_SIZE,row-1,col-1,playerSymbol);

	checkBoardUpLeft(board,MAX_SIZE,row-1,col-1,playerSymbol);

	checkBoardDownRight(board,MAX_SIZE,row-1,col-1,playerSymbol);

	checkBoardDownLeft(board,MAX_SIZE,row-1,col-1,playerSymbol);

	printBoard(board,MAX_SIZE,boardSize);

	turnCount++;
    }
    //starting end of game count
    for (int count=0;count<boardSize;count++)
        {
          for (int count1=0;count1<boardSize;count1++)
	    {
	      //adding one for each instance of X and O
            if (board[count][count1]=='X'){
              xCount++;
            }
            else
            {
              oCount++;
            }
            }
          }
          
    //printing final score then leaving the game
    cout<<"The Game is over"<<"\n"<<"Player X controls "<<xCount<<" squares."<<"\n"<<"Player O controls "<<oCount<<" squares."<<"\n";
     if (xCount>oCount){
        cout<<"Player X wins!"<<"\n";
      }
      else if (xCount<oCount){
        cout<<"Player O wins!"<<"\n";
      }
      else
      {
        cout<<"The game is a tie!"<<"\n";
      }
      
        
      }
  //in case of out of bounds input in command line
   else
     {
       cout<<"Board must be an even size between 4 and 10."<<"\n";
     }
   return 0;
  }

