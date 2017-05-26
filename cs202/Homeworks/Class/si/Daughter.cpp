#include <string>

using namespace std;

class Daughter : public Momma
{
public:
	Daughter();
	virtual ~Daughter();
	void SayName();
	
private:
	//string m_name = daughter;
	
};

Daughter::Daughter(){}

Daughter::~Daughter()
{
	cout<<"Daughter destruct..."<<endl;
}
void Daughter::SayName()
{
	cout<<"My name is daughter"<<endl;
}