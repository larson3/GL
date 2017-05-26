#include <iostream>
#include "Card.h"

Card::Card(){}

Card::Card(int type, string desc)
{
	m_type = type;
	m_desc = desc;
}

int Card::GetType()
{
	return m_type;
}

string Card::ToString()
{
	return m_desc;
}