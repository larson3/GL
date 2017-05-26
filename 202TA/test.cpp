#include <iostream>
using namespace std;

int main () {
  int a = 0;
  int c = ++a ? 123 : 456;
  cout << "c = " << c << endl;

  return 0;
}
