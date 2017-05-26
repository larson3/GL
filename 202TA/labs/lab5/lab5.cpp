#include "File.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void populateDirectory(vector<File>&);
// fill vector - fills file info
// @param vector<File>& - files in directory
void printDirectory(vector<File>&);
//printDirectory - prints the information of the files in the directory
//@param const vector<File>& files in directory 

int main () {
	//Creates a new directory of files
  vector<File> myDirectory;
	//Populates the vector
  populateDirectory(myDirectory);
  //Prints the contents of the vector
  printDirectory(myDirectory);
  return 0;
}

void populateDirectory(vector<File>& newDirectory) {
  
  //Write this function
  //Needs to ask how many files
  //Gets file name, file type, and file size
  //Uses the overloaded constructor for the file
  //Needs to add files to the directory vector
  int numFiles;
  string temp;
  int temp2;
  File tempFile;
  cout<<"How many files"<<endl;
  cin>>numFiles;
  for(int i=0;i<numFiles;i++)
  {
	  newDirectory.push_back(tempFile);
	  cout<<"File "<<i<<endl;
	  cout<<"File Name:"<<endl;
	  cin>>temp;
	  newDirectory[i].SetFileName(temp);
	  cout<<"File Type:"<<endl;
	  cin>>temp;
	  newDirectory[i].SetFileType(temp);
	  cout<<"File Size (in kB):"<<endl;
	  cin>>temp2;
	  newDirectory[i].SetFileSize(temp2);

  }
}

void printDirectory(vector<File>& newMyFile){
  //Needs to loop through the directory of files and outputs the information
  for(unsigned int i = 0;i<newMyFile.size();i++)
  {
	  cout<<"File Name: "<<newMyFile[i].GetFileName()<<endl;
	  cout<<"File Type: "<<newMyFile[i].GetFileType()<<endl;
	  cout<<"File Size: "<<newMyFile[i].GetFileSize()<<endl;

  }
}
