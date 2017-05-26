#include "Scented.h"

Scented::Scented(string name, double burnRate, string flavor)
: Candle(name, burnRate)
{

	m_flavor = flavor;
}
	
string Scented::GetFlavor()
{
	return m_flavor;
}

void Scented::SetFlavor(string flavor)
{
	m_flavor = flavor;
}

void Scented::SetLit(bool isLit)
{
	m_isLit = true;
	cout<<"The delicious smell of "<<m_flavor<<" fills the air."<<endl;
	}