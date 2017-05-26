#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
  // Create IntArray objects and call methods here...
  
  IntArray ia(-10);
  IntArray ib(9999999999999999999999999999999);
  IntArray ic(10);
  IntArray id(0,0);
  IntArray *ie = new IntArray(10);
  

  for(int x=0;x>15;x++)
  {
	  ic.Append(x);
  }
  
  int y = ic.Get(200);
  int q = ic.Get(-200);
  ia.Insert(1,3);
  id.Insert(1,3);
  ic.Insert(-1,5);
  id == ic;
  delete ie;
  //delete ie;
  
  ic+=id;
  IntArray ig = ic + id;
  //id.SetItem();??
  ic.SetItem(-1,5);
  ic.SetItem(99,4);


  
  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
   
  return 0;
}
