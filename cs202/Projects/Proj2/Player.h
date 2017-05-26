/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  John Larson
 * Date:    10/11/14
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 *   This file contains the declaration for the Blackjack class.
 *   The class manages and implements the mechanics for a multi-player
 *   version of the Blackjack/21 program, including bets.
 *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
class Player 
{
  public:
	/****************************************************************
     * Name: Player()
     *   
     * Preconditions: none.
     * Postconditions:Creates a player Jane with bank 100
     *   
     ****************************************************************/
  Player();
  
    /****************************************************************
     * Name: Player(funds,names)
     *   
     * Preconditions: none.
     * Postconditions:Creates a player object with the name taken from array, gives a bank of 100.
     *   
     ****************************************************************/
  
  Player(char *names);
  
  /****************************************************************
     * Name: GetPlayers()
     *   
     * Preconditions: Valid player object
     * Postconditions: Returns the name of the player at the selected vector spot
     *   
     ****************************************************************/
  char *GetPlayers();
  
    /****************************************************************
     * Name: GetFunds() const
     *   
     * Preconditions: Valid player object
     * Postconditions: Returns the funds of the player at the selected vector spot
     *   
     ****************************************************************/
	 
   int GetFunds() const;
  
/****************************************************************
     * Name: SetBet(amt)
     *   
     * Preconditions: Valid player object and bet int
     * Postconditions: Set the chosen valid bet of the player
     *   
     ****************************************************************/
  void SetBet(int amt);
  
  /****************************************************************
     * Name: GetBet()
     *   
     * Preconditions: Valid player
     * Postconditions: Retrieves the chosen valid bet of the player
     *   
     ****************************************************************/
  int GetBet() const;
  
    /****************************************************************
     * Name: SetFunds() const
     *   
     * Preconditions: Valid player object
     * Postconditions: Set the funds of the player at the selected vector spot
     *   
     ****************************************************************/
  void SetFunds(int funds);
  
   /****************************************************************
 * Name: SetCard(Card card)
 *   
 * Preconditions: A card from the deck
 * Postconditions: Calls calls a function which will add the card to the player's hand
 *   
 ****************************************************************/
  void SetCard(Card card);
  
   /****************************************************************
 * Name: DisplayPlayerHand()
 *   
 * Preconditions:
 * Postconditions: Prints the player's hand in an accessible manner
 *   
 ****************************************************************/
  void DisplayPlayerHand();
  
   /****************************************************************
 * Name: DisplayDealerHand()
 *   
 * Preconditions:
 * Postconditions: Prints the dealer's hand in an accessible manner
 *   
 ****************************************************************/
  void DisplayDealerHand();
  
 /****************************************************************
 * Name: GetOutputLast()
 *   
 * Preconditions:
 * Postconditions: Calls a function which will print the last card in the player's hand
 *   
 ****************************************************************/
  void GetOutputLast();
  
 /****************************************************************
 * Name: GetHandValue()
 *   
 * Preconditions:
 * Postconditions: Returns the int value of the player's hand
 *   
 ****************************************************************/
  int GetHandValue();
  
   /****************************************************************
 * Name: LookAces()
 *   
 * Preconditions:
 * Postconditions: Calls a function which will check for any aces in the Player's hand and change their value
 *   
 ****************************************************************/
  bool LookAces();
  
 /****************************************************************
 * Name: SetBust()
 *   
 * Preconditions:
 * Postconditions: Will change the player's status to busted
 *   
 ****************************************************************/
  void SetBust();
  
   /****************************************************************
 * Name: SetBustNew()
 *   
 * Preconditions:
 * Postconditions: Resets the player's status to not busted
 *   
 ****************************************************************/
  void SetBustNew();
  
 /****************************************************************
 * Name: GetBust() const
 *   
 * Preconditions:
 * Postconditions: Returns the player's busted status
 *   
 ****************************************************************/
  bool GetBust() const;
  
 /****************************************************************
 * Name: SetWin()
 *   
 * Preconditions:
 * Postconditions: Adds the bet to the Player's funds
 *   
 ****************************************************************/
  void SetWin();
  
   /****************************************************************
 * Name: SetLoss()
 *   
 * Preconditions:
 * Postconditions: Subtracts the bet from the Player's funds
 *   
 ****************************************************************/
  void SetLoss();
  
 /****************************************************************
 * Name: IsBlackjack()
 *   
 * Preconditions:
 * Postconditions: Calls a function which will check the player's hand for blackjack
 *   
 ****************************************************************/
  bool IsBlackjack();
  
 /****************************************************************
 * Name: NewHand()
 *   
 * Preconditions:
 * Postconditions: Clears the hand vector for the player
 *   
 ****************************************************************/
  void NewHand();
  
  private:
	
	char *m_player;
	int m_funds;
	int defaultValue;
	bool m_busted;
	int m_bet;
	Hand m_playerHand;
	char*tempPlayer;
};
#endif