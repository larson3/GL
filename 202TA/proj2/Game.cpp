#include <iostream>
#include "Game.h"

Game::Game()
{
	int deckSize;
	int players;
	string file = DECK_NAME;
	
	cout<<"MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW"<<endl;
	cout<<"Welcome to Exploding Kittens"<<endl;
	cout<<"A Game By Elan Lee, Shane Small, and Matthew Inman"<<endl;
	cout<<"MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW"<<endl;
	cout<<"How many players would you like?"<<endl;
	cout<<"Choose 2 - 4 players:"<<endl;
	cin>>players;
	SetNumPlayers(players);
	deckSize = LoadDeck(file);
	//TODO deal the cards to players
	Shuffle();
}

void Game::SetNumPlayers(int numPlayers)
{
	m_numPlayers = numPlayers;
}

void Game::Shuffle()
{
	cout<<"Hi"<<endl;
}

int Game::LoadDeck(string fileName)
{
	int tempType;
	string tempDesc;
	int count = 0;
	string line;
	fstream file;
	file.open(fileName.c_str());
	while(getline(file,line))
	{
		if(count%2 == 0)
		{
			tempType = atoi(line.c_str());
		}
		else if(count%2 == 1)
		{
			tempDesc = line;
			Card newCard = Card(tempType,tempDesc);
			m_deck.push_back(newCard);
		}
		count++;
	}
	/*for(unsigned int i = 0;i<m_deck.size();i++)
	{
		cout<<m_deck[i].ToString()<<endl;
		cout<<m_deck[i].GetType()<<endl;
	}*/

	return count;
}