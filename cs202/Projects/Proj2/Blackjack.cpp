#include <cstdlib>
#include <iostream>
#include "Blackjack.h"


using namespace std;

Blackjack::Blackjack()
{
	

	Player newPlayer;
	
	m_players.push_back(newPlayer);
	
}

Blackjack::Blackjack(char *names[], int numPlayers)
{
	
	for (int x=0;x<numPlayers;x++){

		Player newPlayer(names[x]);
		m_players.push_back(newPlayer);
		
		
		
	}
}
int Blackjack::GetNumPlayers()
{
	return m_players.size();
}   

char *Blackjack::GetPlayerName(int player)
{
	return m_players[player].GetPlayers();
}

int Blackjack::GetPlayerFunds(int player)
{
	return 	m_players[player].GetFunds();
}

void Blackjack::SetPlayerFunds(int player, int amt)
{
	
	m_players[player].SetFunds(amt);
}

bool Blackjack::SetPlayerBet(int player, int amt)
{
	//this gives a bool value to main which provides all the output
	currentFunds=GetPlayerFunds(player);
	
	if (amt <= currentFunds && amt >= 0)
	{
		m_players[player].SetBet(amt);
		return true;
	}
	else
	{
		return false;
	}
}
	

void Blackjack::NewDeal()
{
	Deck m_deck;
	m_deck.Shuffle();
	players = GetNumPlayers();
	for (int x = 0;x < players;x++)
		{
		m_players[x].NewHand();
		m_players[x].SetBustNew();
		m_dealer.SetBustNew();
		}
	m_dealer.NewHand();
	for (int x = 0;x < players;x++)
	{
		
		newCard=m_deck.DealCard();
		m_players[x].SetCard(newCard);
		
	}
	newCard=m_deck.DealCard();
	m_dealer.SetCard(newCard);
	
	//going around again
	for (int x=0;x<players;x++)
	{
		
		newCard=m_deck.DealCard();
		m_players[x].SetCard(newCard);
	}
	newCard=m_deck.DealCard();
	m_dealer.SetCard(newCard);
}

void Blackjack::OutputPlayerHand(int player)
{
	m_players[player].DisplayPlayerHand();
}

void Blackjack::OutputDealerHand()
{
	m_dealer.DisplayDealerHand();
}


bool Blackjack::HitPlayer(int player)
	{
		int m_bust = 22;
		newCard=m_deck.DealCard();
		m_players[player].SetCard(newCard);
		m_players[player].GetOutputLast();
		m_handTotal=m_players[player].GetHandValue();
		cout<<m_handTotal<<endl;
		if (m_handTotal<m_bust)
		{
			
			return false;
			
		}
		else
		{
			
			if (m_players[player].LookAces())
			{
				return false;
			}
			else
			{
			m_players[player].SetBust();
			return true;
		    }
		}
		
	}	

void Blackjack::DealerPlay()
{
	int m_bust = 22;
	int m_dealerMax = 17;
	m_handTotal=m_dealer.GetHandValue();
	
	while (m_handTotal < m_dealerMax)
		{
		newCard = m_deck.DealCard();
		m_dealer.SetCard(newCard);
		m_handTotal = m_dealer.GetHandValue();
		
		}
	if (m_handTotal >= m_bust)
		{
		m_dealer.SetBust();
		cout<<"Dealer has busted"<<endl;
		}
	else if (m_dealer.IsBlackjack())
	{
	cout<<"Dealer has Blackjack"<<endl;
	}
	else
	{
	cout<<"Dealer has "<<m_handTotal<<endl;
	}
}	

int Blackjack::SettlePlayerBet(int player)
	{
		m_handTotal=m_players[player].GetHandValue();
		m_dhandTotal=m_dealer.GetHandValue();
		
		m_bet=m_players[player].GetBet();
		
		
		if (m_players[player].GetBust())
		{
			//player loses by busting
			m_players[player].SetLoss();
			cout<<m_players[player].GetPlayers();
			cout<<" has busted--Dealer wins."<<endl;
			
			return 0;
		}
		
		else if (m_dealer.GetBust())
		{
			//dealer loses by busting
			m_players[player].SetWin();
			cout<<"Dealer has busted--";
			cout<<m_players[player].GetPlayers()<< " wins"<<endl;
			
			return 0;
		}
			
		else if(m_players[player].IsBlackjack())
		{
			if (m_dealer.IsBlackjack())
			{
				//tie both blackjack
				cout<<"Both have Blackjack, hand is a tie."<<endl;
				return 0;
			}
			else
			{
			//player wins with blackjack
			m_players[player].SetWin();
			cout<<m_players[player].GetPlayers();
			cout<<" has Blackjack--"<<m_players[player].GetPlayers()<<" wins"<<endl;
			return 0;
			}
		}
		else if(m_dealer.IsBlackjack())
		{
			if (m_players[player].IsBlackjack())
			{
				//tie both blackjack
				cout<<"Both have Blackjack, hand is a tie."<<endl;
				return 0;
			}
			else
			{
				//player loses, dealer blackjack
				m_players[player].SetLoss();
				cout<<"Dealer has Blackjack--Dealer wins"<<endl;
				return 0;
			}
		}
		else if (m_handTotal<m_dhandTotal)
		{
			//player loses dealer high hand
			m_players[player].SetLoss();
			cout<<m_players[player].GetPlayers()<<" has "<<m_handTotal;
			cout<<"--Dealer wins"<<endl;
			return 0;
		}
		else if (m_handTotal>m_dhandTotal)
		{
			//player wins high hand
			m_players[player].SetWin();
			cout<<m_players[player].GetPlayers()<<" has "<<m_handTotal;
			cout<<"--"<<m_players[player].GetPlayers()<<" wins"<<endl;
			return 0;
		}
		else
		{
			//tie, same hands
			cout<<"Hands are the same, tie"<<endl;
			return 0;
		}
				
			
		return 0;
		}

