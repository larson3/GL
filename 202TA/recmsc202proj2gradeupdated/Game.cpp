/*****************************************
  ** File:    Game.cpp
  ** Project: CMSC 202 Project 2, Spring 2017
  ** Author:  Daniel Lee
  ** Date:    3/9/2017
  ** Section: 13
  ** E-mail:  danlee1@umbc.edu
  **
  ** This file implements the Game class.
  *****************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h> 

#include "Card.h"
#include "Player.h"
#include "Game.h"

// global constants
const string PLAYER_ONE = "Player 1";
const string PLAYER_TWO = "Player 2";
const string PLAYER_THREE = "Player 3";
const string PLAYER_FOUR = "Player 4";

//// Constructors ////
// default constructor
Game::Game() {
  // render game intro and get number of players from user
  cout << endl; cout << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW" << endl;
  cout << "Welcome to Exploding Kittens" << endl;
  cout << "A Game By Elan Lee, Shane Small, and Mathew Inman" << endl;
  cout << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW" << endl;

  int numPlayers;
  cout << endl;
  cout << "How many players would you like?" << endl;
  cout << "Choose 2 - 4 players: " << endl;
  cout << endl;
  cin >> numPlayers;
  while ((numPlayers < 2) || (numPlayers > 4)) {
    cout << numPlayers << " is not a valid choice. Please enter a number between 2 and 4:" << endl;
    cin >> numPlayers;
  }

  // set m_numPlayers to numPlayers from user input
  SetNumPlayers(numPlayers);
  // create a set of player objects and add them to an array of m_players
  string playerNames[4] = {PLAYER_ONE, PLAYER_TWO, PLAYER_THREE, PLAYER_FOUR};
  for (int i = 0; i < m_numPlayers; i++) {
    m_players[i]  = Player(playerNames[i]);
  }
  // read deck.txt into vector m_deck
  LoadDeck(DECK_NAME);
  // shuffle m_deck
  Shuffle();

  // deal out 4 initial cards to each player
  cout << endl; cout << "////////  Dealing  ////////" << endl; 
  for (int i = 0; i < INIT_CARDS; i++) {
    for (int i = 0; i < m_numPlayers; i++) {
      m_players[i].AddToHand(m_deck[i]);
      m_deck.erase(m_deck.begin() + i);
    }
  }
  // shuffle into m_deck the bomb cards from bomb.txt
  AddBombCards(BOMB_NAME); 
  cout << endl; cout << "Number of cards remaining: " << m_deck.size() << endl;
  
  // begin game
  PlayGame();

} 

void Game::SetNumPlayers(int numPlayers) {
  m_numPlayers = numPlayers;
}

int Game::LoadDeck(string DECK_NAME) {
  string cardNum;
  string cardDesc;
  fstream inputStream;
  inputStream.open(DECK_NAME.c_str()); 
  while (getline(inputStream, cardNum)) { 
    int cardInt = atoi(cardNum.c_str());
    getline(inputStream, cardDesc);
    m_deck.push_back(Card(cardInt, cardDesc));
  }
  inputStream.close();

  return 0;
}

void Game::Shuffle() {
  cout << endl; cout << "////////  Shuffling the cards  ////////" << endl;
  srand(RAND_SEED);
  for (int i = 0; i < m_deck.size(); i++) {
    int randomCardNum = rand() % m_deck.size();
    Card tempCard = m_deck[i];
    m_deck[i] = m_deck[randomCardNum];
    m_deck[randomCardNum] = tempCard;
  }
}

int Game::AddBombCards(string BOMB_NAME) {
  cout << endl; cout << "////////  Shuffling in the exploding kittens!  ////////" << endl;
  string bombNum;
  string bombDesc;
  fstream inputStream;
  srand(RAND_SEED);
  int randomBombNum = rand() % m_deck.size();
  inputStream.open(BOMB_NAME.c_str()); 
  while (getline(inputStream, bombNum)) { 
    int bombInt = atoi(bombNum.c_str());
    getline(inputStream, bombDesc);
    m_deck.insert(m_deck.begin() + randomBombNum, Card(bombInt, bombDesc));
  }
  inputStream.close();

  return 0;
}

Card Game::DrawCard() {
  Card drawnCard = m_deck[0];
  // m_deck.erase(m_deck.begin() + drawnCard.ToString());
  return drawnCard;
}

void Game::PlayGame() {
  int playerTurn = 0;
  bool gameRunning = true;
  while (gameRunning) {
    if (m_players[playerTurn].HasLost()) {
      if (playerTurn == (m_numPlayers - 1)) {
        playerTurn = 0;
      }
      else {
        playerTurn++;
      }
    }
  }
  int choiceGameMenu;
  for (int i = 0; i < m_numPlayers; i++) {
    cout << endl; cout << "It is " << m_players[i].GetName() << "'s turn" << endl;
    cout << endl; cout << "What would you like to do:" << endl;
    cout << "1. View Cards" << endl;
    cout << "2. Play A Card" << endl;
    cout << "3. Draw A Card" << endl; cout << endl;
    cout << endl;
    cin >> choiceGameMenu; cout << endl;
    while ((choiceGameMenu < 1) || (choiceGameMenu > 3)) {
      cout << choiceGameMenu << " is not a valid choice. Please enter a number between 1 and 3:" << endl;
      cin >> choiceGameMenu;
    }
    switch (choiceGameMenu) {
      // View Cards
      case 1: {
        m_players[i].DisplayHand();
        break;
      }
      // Play A Card
      case 2: {
        // m_players[i].DisplayHand();
        // Card playedCard = m_players[i].PlayCard();
        
        // m_discard.push_back(playedCard);

        // int someIntegerValue = HandleCard(i);
        
        break;
      }
      // Draw A Card
      case 3: {
        // Card newCard = DrawCard();
        // if (newCard.GetType() == 0) {
        //   cout << "Oh No! You drew Exploding Kitten: " << newCard.ToString() << endl;
          
        // m_players[i].DisplayHand();
        // Card playedCard = m_players[i].PlayCard();
        // m_discard.push_back(playedCard);
        break;
      }
    }
    cout << "You're out of the game!" << endl;
  }  
  cout << "The winner is " << m_players[0].GetName() << "!" << endl; cout << endl;
}

// int HandleCard(int currentPlayer) {
  
//   m_players[currentPlayer];
// }

// void Game::Peek() {}
