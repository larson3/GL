#include <iostream>
#include <cstdlib>
#include "Hand.h"
#include "Deck.h"

using namespace std;

Hand::Hand()
{
	
}

void Hand::GiveCard(Card card)
 {
		//adding a card to a temp variable, then pushing into hand vector
		m_tempCard = card;
		m_hand.push_back(m_tempCard);
}

void Hand::OutputCards()
	{
		m_handSize = m_hand.size();
		for (int x=0;x<m_handSize;x++)
		{
			m_hand[x].OutputCard();
			if (x+1<m_handSize)
			{
				cout<<", ";
			}
		}
	}
	
void Hand::OutputDealerCards()
{
	firstCard = 0;
	m_hand[firstCard].OutputCard();
	cout<<','<<" [Hidden Card]";
}

void Hand::OutputLast()
{
	m_handSize = m_hand.size() -2;
	m_handSize++;
	
	m_hand[m_handSize].OutputCard();
	cout<<endl;
}

int Hand::ReturnHandValue()
{	
	m_handValue = 0;
	m_handSize=m_hand.size();
	for (int x=0;x<m_handSize;x++)
	{
		m_tempValue = m_hand[x].GetBlackjackValue();
		
		
		if (m_tempValue == 1)
		{
			m_tempValue = 11;
		}
		
		m_cardValue.push_back(m_tempValue);
		m_handValue+=m_tempValue;
		
	}
	return m_handValue;
}

bool Hand::CheckAces()
{
	m_handSize = m_hand.size();
	for (int x=0;x<m_handSize;x++)
	{
		
		
		if (m_cardValue[x] == 11)
			{
			m_cardValue[x] = 1;
			return true;
			}
		
	}
	return false;
}

bool Hand::GetBlackjack()
{
	m_handSize = m_hand.size();
	m_blackjackValue = 0;
	if (m_handSize == 2)
	{
		for (int x=0;x<m_handSize;x++)
		{
			m_tempValue = m_hand[x].GetBlackjackValue();
			m_blackjackValue += m_tempValue;
		}
		
		if (m_blackjackValue == 21 || m_blackjackValue == 11)
		{
			return true;
		}
		else
		{
		return false;
		}
	}
	else
	{
	return false;
	}
}


void Hand::ClearHand()
{
	m_hand.clear();
}