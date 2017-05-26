#include <stdlib.h> 
#include <iostream>
#include <string.h>
#include <fstream>
#include "proj1.h"
using namespace std;

int main(int argc, char *argv[])
{

	game = 1;
	cout<<"What would you like to do?"<<endl<<"1. Load simulation from a file"<<endl;
	cout<<"2. Start a new simulation"<<endl<<"3.Exit"<<endl<<"Enter 1 - 3."<<endl;
	cin>>whatDo;
	if(whatDo == 1)
	{
		cout<<"What is the name of your file?"<<endl;
		cin >> input;
		fstream file;
		file.open(input);
		if(file.fail())
		{
			cout<<"Bad file name!"<<endl;
			exit(0);
		}
		file >> playerX;
		file >> playerY;
		file >> targetX;
		file >> targetY;
		file.close();
	}
	else if(whatDo == 2)
	{
		cout<<"What is the X axis of the investigator?"<<endl;
		cin>>playerX;
		cout<<"What is the Y axis of the investigator?"<<endl;
		cin>>playerY;
		cout<<"What is the X axis of the target?"<<endl;
		cin>>targetX;
		cout<<"What is the Y axis of the target?"<<endl;
		cin>>targetY;
	}
	else{
		cout<<"Seeya"<<endl;
		exit(0);
	}
	for(y=0;y<size;y++)
	{
		for(x=0;x<size;x++)
		{
			grid[y][x] = '_';

		}
	}
	while(game)
	{
		inputLoop = 1;
		grid[playerY][playerX] = '*'; 
		for(y=0;y<size;y++)
		{
			for(x=0;x<size;x++)
			{
				if(y == playerY and x == playerX)
				{
					cout<<"I ";
				}
				else{
					cout<<grid[y][x]<<' ';
				}
			}
			cout<<"\n";		
		}
		while(inputLoop)
		{
			cout<<"Enter direction."<<endl<<"1. Up"<<endl<<"2. Down"<<endl<<"3. Left"<<endl<<"4. Right"<<endl<<"5. Exit"<<endl;
			if(cin.peek()=='\n')
				{
					cin.ignore();
				}
			cin>>userInput;
			if(userInput == 1)
			{
				inputLoop = up(playerY);
				if(inputLoop == 0)
				{
					playerY--;
				}
			}
			if(userInput == 2)
			{
				inputLoop = down(playerY);
				if(inputLoop == 0)
				{
					playerY++;
				}
			}		
			if(userInput == 3)
			{
				inputLoop = left(playerX);
				if(inputLoop == 0)
				{
					playerX--;
				}
			}		
			if(userInput == 4)
			{
				inputLoop = right(playerX);
				if(inputLoop == 0)
				{
					playerX++;
				}
			}
			if(userInput == 5)
			{
				cout<<"Thx"<<endl;
				inputLoop = 0;
				game = 0;
			}
		}
		if(playerX == targetX and playerY == targetY)
		{
			cout<<"You found the target!"<<endl;
			game = 0;
		}
		else if(playerX != targetX)
		{
			if(playerX > targetX)
			{
				cout<<"Try searching to the left"<<endl;
			}
			else{
				cout<<"Try searching to the right"<<endl;
			}
		}
		else{
			if(playerY > targetY)
			{
				cout<<"Try searching up"<<endl;
			}
			else{
				cout<<"Try searching down"<<endl;
			}
		}
		
	}
	return 0;
}

int up(int playerY)
{
	if(playerY - 1 < 0)
	
	{
		cout<<"Out of bounds!  Try again!"<<endl;
		return 1;
	}
	cout<<"Going up"<<endl;
	return 0;
}

int down(int playerY)
{
	if(playerY + 1 > size-1)
	{
		cout<<"Out of bounds!  Try again!"<<endl;
		return 1;
	}
	return 0;
}

int right(int playerX)
{
	if(playerX + 1 > size-1)
	{
		cout<<"Out of bounds!  Try again!"<<endl;
		return 1;
	}
	return 0;
}

int left(int playerX)
{
	if(playerX - 1 < 0)
	{
		cout<<"Out of bounds!  Try again!"<<endl;
		return 1;
	}
	return 0;
}