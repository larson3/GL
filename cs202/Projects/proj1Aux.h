/*****************************************
 ** File:    Proj1Aux.h
 ** Project: CMSC 202 Project 1, Fall 2014
 ** Author:  John Larson
 ** Date:    10/1/2014
 ** Section: 7
 ** E-mail:  larson3@umbc.edu
 ** This file contains the headers for the file proj1.cpp and proj1AUX.cpp
 ** it includes function declarations as well as constants.
 ***********************************************/


#ifndef PROJ1AUX_H_
#define PROJ1AUX_H_

const int MAX_SIZE=10;
const int MIN_SIZE=4;

//-------------------------------------------------------
// Name: printBoard
// PreCondition:  board must be declared as a 2D-array
// PostCondition: Returns a visual representation of the array
//---------------------------------------------------------
void printBoard(char board[][MAX_SIZE],int MAX_SIZE,int boardSize);

//-------------------------------------------------------
// Name: whichPlayer
// PreCondition:  
// PostCondition: Returns a symbol 'X' or 'O'
//---------------------------------------------------------
char whichPlayer(int turnCount);

//-------------------------------------------------------
// Name: GetNextMove
// PreCondition:
// PostCondition: Returns the coordinates of the player's move
//---------------------------------------------------------
void GetNextMove(char playerSymbol,int &row, int &col);

//-------------------------------------------------------
// Name: validMove
// PreCondition:  A pair of numbers input by the user
// PostCondition: Returns a bool value of true/false if the move is legal
//---------------------------------------------------------
bool validMove(char playerSymbol, int row, int col, int boardSize,char board[][MAX_SIZE],int MAX_SIZE);

//-------------------------------------------------------
// Name: updateBoard
// PreCondition:  a valid move and declared board
// PostCondition: Returns a board with a new symbol at the chosen spot
//---------------------------------------------------------
void updateBoard(char (&board)[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol,int boardSize);

//-------------------------------------------------------
// Name: checkBoardRight
// PreCondition:  a valid move
// PostCondition: Checks to the right, and returns either a flip or nothing
//---------------------------------------------------------
void checkBoardRight(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);

//-------------------------------------------------------
// Name: checkBoardLeft
// PreCondition:  a valid move
// PostCondition: Checks to the left, and returns either a flip or nothing
//---------------------------------------------------------
void checkBoardLeft(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);

//-------------------------------------------------------
// Name: checkBoardUp
// PreCondition:  a valid move
// PostCondition: Checks up, and returns either a flip or nothing
//---------------------------------------------------------
void checkBoardUp(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);

//-------------------------------------------------------
// Name: checkBoardDown
// PreCondition:  a valid move
// PostCondition: Checks down, and returns either a flip or nothing
//---------------------------------------------------------
void checkBoardDown(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);

//-------------------------------------------------------
// Name: checkBoardUpRight
// PreCondition:  a valid move
// PostCondition: Checks to the right and up, and returns either a flip or 
// nothing
//---------------------------------------------------------
void checkBoardUpRight(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);

//-------------------------------------------------------
// Name: checkBoardUpLeft
// PreCondition:  a valid move
// PostCondition: Checks to the left and up, and returns either a flip or
// nothing
//---------------------------------------------------------

void checkBoardUpLeft(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);

//-------------------------------------------------------
// Name: checkBoardDownRight
// PreCondition:  a valid move
// PostCondition: Checks to the right and down, and returns either a flip or
// nothing
//---------------------------------------------------------

void checkBoardDownRight(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);

//-------------------------------------------------------
// Name: checkBoardDownLeft
// PreCondition:  a valid move
// PostCondition: Checks to the left and down, and returns either a flip or
// nothing
//---------------------------------------------------------

void checkBoardDownLeft(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);



#endif
