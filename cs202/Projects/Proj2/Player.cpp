#include <cstdlib>
#include <iostream>
#include "Player.h"


using namespace std;


Player::Player()
{
	
	m_funds=100;
	char *temp="Jane";
	
	m_player = temp;
	
}

Player::Player(char *names)
{
	defaultValue=100;
	m_funds = defaultValue;
	m_player = names;	
}

char *Player:: GetPlayers()
{
	return m_player;
}

void Player::SetFunds(int funds)
{
m_funds = funds;

}

int Player::GetFunds() const
{
	return m_funds;
}

void Player::SetBet(int amt)
{
	m_bet = amt;
}

int Player::GetBet() const 
{
	return m_bet;
}

void Player::SetCard(Card card)
{
	m_playerHand.GiveCard(card);
}

void Player::DisplayPlayerHand()
{
	m_playerHand.OutputCards();
}

void Player::DisplayDealerHand()
{
	m_playerHand.OutputDealerCards();
	
}

void Player::GetOutputLast()
{
	m_playerHand.OutputLast();
}

int Player:: GetHandValue()
{
	return m_playerHand.ReturnHandValue();
}

bool Player::LookAces()
{
	return m_playerHand.CheckAces();
}

void Player::SetBust()
{
	m_busted = true;
}

void Player::SetBustNew()
{
	m_busted = false;
}

bool Player::GetBust() const
{
	return m_busted;
}

void Player::SetLoss()
{
	m_funds -= m_bet;
}

void Player::SetWin()
{
	m_funds += m_bet;
}

bool Player::IsBlackjack()
{
	return m_playerHand.GetBlackjack();
}

void Player::NewHand()
{
	m_playerHand.ClearHand();
}