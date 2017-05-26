/*****************************************
  ** File:    Player.cpp
  ** Project: CMSC 202 Project 2, Spring 2017
  ** Author:  Daniel Lee
  ** Date:    3/9/2017
  ** Section: 13
  ** E-mail:  danlee1@umbc.edu
  **
  ** This file implements the Player class.
  *****************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

// //// Constructors ////
// // default constructor 
Player::Player() {}

Player::Player(string playerName) {
  m_name = playerName;
}

// // Accessors ////
string Player::GetName() {
  return m_name;
}

int Player::GetNumberOfCards() {
  return m_hand.size();
}

void Player::SetLost(bool hasLost) {
  if (hasLost == true) {
    m_lost = true;
  } 
  m_lost = false;
}

void Player::SetExtraTurn(bool hasExtraTurn) {
  if (hasExtraTurn == true) {
    m_extraTurn = true;
  } 
  m_extraTurn = false;
}

//// Helper Methods ////
bool Player::HasLost() {
  if (true) {
    return 1;
  }
  else{
    return 0;
  }
}

bool Player::HasCards() {
  if (m_hand.size() != 0) {
    return true;
  }
  return false;
}

bool Player::HasExtraTurn() {
  return m_extraTurn;
}

int Player::AddToHand(Card newCard) {
  m_hand.push_back(newCard);
  return 0;
}

void Player::DisplayHand() {
  for (int i = 0; i < m_hand.size(); i++) {
    // edit description of those cards with abilities
    switch (m_hand[i].GetType()) {
      case 1: {
        cout << (i + 1) << ". Defuse: " << m_hand[i].ToString() << endl;
        break;
      }
      case 2: {
        cout << (i + 1) << ". Attack: " << m_hand[i].ToString() << endl;
        break;
      }
      case 3: {
        cout << (i + 1) << ". Skip: " << m_hand[i].ToString() << endl;
        break;
      }
      case 4: {
        cout << (i + 1) << ". See-The-Future: " << m_hand[i].ToString() << endl;
        break;
      }
      case 5: {
        cout << (i + 1) << ". Shuffle: " << m_hand[i].ToString() << endl;
        break;
      }
      default: {
        cout << (i + 1) << ". " << m_hand[i].ToString() << endl;
        break;
      }
    }
  }
}

Card Player::PlayCard() {
  int playedCardIndex;
  cout << "Select a card: " << endl;
  cin >> playedCardIndex;

  m_hand.erase(m_hand.begin() + playedCardIndex);
  return m_hand[playedCardIndex]; 
}

/*Card Player::LoseCard(int loserNum) {
  m_players[loserNum];  
  m_hand[i].erase(m_hand.begin() + i);
}

Card Player::ReturnBomb() {
  
}
*/