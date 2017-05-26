#include <string>

using namespace std;

class Momma
{
public:
	Momma();
	virtual ~Momma();
	void SayName();
private:
	//string m_name = "Momma";
};

Momma::Momma(){}
Momma::~Momma()
{
	cout << "Destructing..."<<endl;
}
void Momma::SayName()
{
	cout<<"My name is Momma"<<endl;
}


