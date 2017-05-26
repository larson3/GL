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
void checkBoardRight(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
void checkBoardLeft(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
void checkBoardUp(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
void checkBoardDown(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
void checkBoardUpRight(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
void checkBoardUpLeft(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
void checkBoardDownRight(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
void checkBoardDownLeft(char board[MAX_SIZE][MAX_SIZE],int MAX_SIZE, int row, int col,char playerSymbol);
