#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
	cout<<"Hello world";
	return 0;
}

Money::Money()
{
	m_cents=0;
	m_dollars=0;
}

Money::Money(int dollars)
{
	m_cents=0;
	m_dollars=dollars;
	
}

Money::Money(int dollars, int cents)
{
	m_cents=cents;
	m_dollars=dollars;
}

void Money::SetDollars(int dollars)
{
	m_dollars=dollars;
}
		
void Money::SetCents(int cents)
{
	m_cents=cents;
}
		
void Money::SetBoth(int dollars, int cents)
{
	m_dollars=dollars;
	m_cents=cents;
}
		
int Money::GetDollars()
{
	return m_dollars;
}

		
int	Money::GetCents()
{
	return m_cents;
}

