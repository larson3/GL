
#include <iostream>
#include <string>
using namespace std;

int main()
{

char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
string red = "\033[1;31mbold red text\033[0m\n";

cout << blue << "This text should be blue" << normal << endl;
cout << red;
cout<<"\033[32mI just made regular green text\033[0m\n";
cout<<"\033[37mThis is white\033[0m\n";
return 0;
}
