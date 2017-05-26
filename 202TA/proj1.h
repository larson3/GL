#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

	
int y,x;
const int size = 10;
int game;
int playerX, playerY, targetX, targetY;
char grid[size][size];
char input[50];
int userInput, whatDo;
int inputLoop;

int up(int playerY);

int down(int playerY);

int right(int playerX);

int left(int playerX);