
/******************************************
** File:    Proj1.cpp
** Project: CMSC 202 Project 1, Spring 2017
** Author:  Marian Gorgy
** Date:    2/17/2017
** Section: 11
** E-mail:  mg16@umbc.edu
**
** 
**
**
**
**
**
**
*******************************************/

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
using namespace std;


const int ROWS = 10;
const int COL = 10;


void startMenu_readFile(int arr1[]);
void loadMap(char map[ROWS][COL], int arr1[]);
int newMap(char map[ROWS][COL], int arr1[], int dir);
int  mainMenu(char map[ROWS][COL], int arr1[]);

void printMap(char map[ROWS][COL]);
//
int main(){

  cout << "Manhunt" << endl;

  int arr1[4] = {};
 
  startMenu_readFile(arr1);
 //    int investigatorX = arr1[0];
        
  char map[ROWS][COL] = {};  

    loadMap(map, arr1);
    
    printMap(map);

    while (arr1[0] != arr1[2] || arr1[1] != arr1[3]){
      mainMenu(map,arr1);
    }

    cout << "You found the target." << endl;

return 0;
}

//
int mainMenu(char map[ROWS][COL], int arr1[]){
  

  int dir;
      do{
	cout << "What would you like to do?" << endl;
	cout << "1. Search North" << endl;
	cout << "2. Search East " << endl;
	cout << "3. Search South" << endl;
	cout << "4. Search West" << endl;
	cout << "5. See Map" << endl; 
	cout << "6. Exit" << endl;
	cout << "Enter 1-6" << endl;
	cin >> dir;

      } while (dir < 1 || dir > 6);

      switch (dir){
     
      case 1:
	
	newMap(map,arr1,dir);
	if (arr1[3] < arr1[1]){ // yT < yI 
	  cout << "Try Searching West" << endl; //w
	}
	
	else if (arr1[3] > arr1[1]){ // yT > yI
	  cout << "Try Searching East" << endl; //e
	}
	
	else if (arr1[2] > arr1[0]){ // xT > xI
	  cout << "Try Searching South" << endl;//s
	}
	
	else if(arr1[2] < arr1[0]){ // xT < xI
	  cout << "Try Searching North" << endl;//n
	}
	break;
	
      case 2:
	
	newMap(map,arr1,dir);
	if (arr1[3] < arr1[1]){
	  cout << "Try Searching West" << endl;
	}
	
	else if (arr1[3] > arr1[1]){
	  cout << "Try Searching East" << endl;
	}
	
	else if (arr1[2] > arr1[0]){
	  cout << "Try Searching South" << endl;
	}
	
	else if(arr1[2] < arr1[0]){
	  cout << "Try Searching North" << endl;
	}     
	break;
	
      case 3:
	
	newMap(map,arr1,dir);
	if (arr1[3] < arr1[1]){
	  cout << "Try Searching West" << endl;
	}
	
	else if (arr1[3] > arr1[1]){
	  cout << "Try Searching East" << endl;
	}
	
	else if (arr1[2] > arr1[0]){
	  cout << "Try Searching South" << endl;
	}
	
	else if(arr1[2] < arr1[0]){
	  cout << "Try Searching North" << endl;
	}
	break;
	
      case 4:

	newMap(map,arr1,dir);
	if (arr1[3] < arr1[1]){ // yT < yI
	  cout << "Try Searching West" << endl; //w
	}
	
	else if (arr1[3] > arr1[1]){ // yT > yI
	  cout << "Try Searching East" << endl; //e
	}
	
	else if (arr1[2] > arr1[0]){ // xT > xI
	  cout << "Try Searching South" << endl;//s
	}
	
	else if(arr1[2] < arr1[0]){ // xT < xI
	  cout << "Try Searching North" << endl;//n
	}     
	break;
	
      case 5:

	break;

      case 6:
	
	cout << "Giving up so soon?" << endl;
	cout << "Good-bye" << endl;
	exit(1);
	break;
      }
      if (arr1[0] == arr1[2] && arr1[1] == arr1[3]){
	return 0;
      }
      else{
      printMap(map);
      }
      return 1;
}
 
//
void printMap(char map[ROWS][COL]){
 
  for (int x=0; x < ROWS; x++){
    for (int y=0; y < COL; y++){
      cout << map[x][y] << " ";
    }
    cout << endl;
  }
}

//
void loadMap(char map[ROWS][COL], int arr1[]){
  cout << "Map loaded" << endl;
  for (int x=0; x < ROWS; x++){
    for (int y=0; y < COL; y++){
      if (x == arr1[0] and y == arr1[1]){
	map[arr1[0]][arr1[1]]= 'I';
      }
      else{
      map[x][y] = '_';
      }
    }
  } 
}

//
int newMap(char map[ROWS][COL], int arr1[], int dir){
       
  if (dir == 1){
    if (map[arr1[0]-1][arr1[1]]== '*'){
      return 0;
    }

    if (arr1[0] == 0){
      cout << "Out of boundaries" << endl;
      return 1;
    }

    else {
      map[arr1[0]][arr1[1]]= '*';
      arr1[0] = arr1[0]-1;
    }
  }

  else if (dir == 2){
    if (map[arr1[0]][arr1[1]+1]== '*'){
      return 0;
    }
    if (arr1[1]== 9){
      cout << "Out of boundaries" << endl;
      return 1;
    }
  
    else {
      map[arr1[0]][arr1[1]]= '*';
      arr1[1] = arr1[1]+1;
    }
  }

  else if (dir == 3){
    if (map[arr1[0]+1][arr1[1]]== '*'){
      return 0;
    }

    if (arr1[0]== 9){
      cout << "Out of boundaries" << endl;
      return 1;
    }
   
    else {
      map[arr1[0]][arr1[1]]= '*';
      arr1[0] = arr1[0]+1; 
    }
  }

  else if (dir == 4){
    if (map[arr1[0]][arr1[1]-1]== '*'){
      return 0;
    }

    if (arr1[1]== 0){
      cout << "Out of boundaries" << endl;
      return 1;
    }
  
    else {
      map[arr1[0]][arr1[1]]= '*';
      arr1[1] = arr1[1]-1;    
    }
  }

  map[arr1[0]][arr1[1]]= 'I';
  return 2;
}

//
void startMenu_readFile(int arr1[]){

  ifstream myFile;
  int xI,yI,xT,yT;
  int option;
  char fileName[20];
  
  do{
  cout << "1. load a simulation from file" << endl;
  cout << "2. start a new simulation" << endl;
  cout << "3. Exit" << endl;
  cout << "Enter 1-3: " << endl;
  cin >> option;

  } while (option < 1 || option > 3);
     
  switch (option)
    {
    case 1:
      
      cout << "What is the name of the file?: " << endl;
      cin >> fileName;
      
      myFile.open(fileName);
      myFile >> xI;
      myFile >> yI;
      myFile >> xT;
      myFile >> yT;
      myFile.close ();

      arr1[0]= xI;
      arr1[1]= yI;
      arr1[2]= xT;
      arr1[3]= yT;

      break;

    case 2:

      do{
      cout << "What is the X axis of the investigator?:" << endl;
      cin >> xI;
      } while ( xI < 0 || xI > 10);

      do{
      cout << "What is the Y axis of the investigator?:" << endl;
      cin >> yI;
      } while ( yI < 0 || yI > 10);

      do{
      cout << "What is the X axis of the target?:" << endl;
      cin >> xT;
      } while ( xT < 0 || xT > 10);

      do{
      cout << "What is the Y axis of the target?:" << endl;
      cin >> yT;
      } while ( yT < 0 || yT > 10);

      arr1[0]= xI;
      arr1[1]= yI;
      arr1[2]= xT;
      arr1[3]= yT;

      break;

    case 3:

      cout << "Giving up so soon?" << endl;
      cout << "Good-bye" << endl;
      exit(1);      
      break; 
    }
}




