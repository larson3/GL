/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Fall 2014
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

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
  public:
    /****************************************************************
     * Name: Hand()
     * Preconditions: none.
     * Postconditions:
     *   Creates a hand
     ****************************************************************/
	Hand();
  
  /****************************************************************
     * Name: SetCard()
     * Preconditions: A card drawn from the deck
     * Postconditions: Stores the drawn card to the Hand class
     *   
     ****************************************************************/
	 void GiveCard(Card card);
	 
	/****************************************************************
     * Name: OutputCards()
     * Preconditions: none.
     * Postconditions: Returns a player friendly representation of the cards in the player's hand
     *   
     ****************************************************************/
	void OutputCards(); 
	
	 /****************************************************************
     * Name: OutputDealerCards()
     * Preconditions: none.
     * Postconditions: Returns a player friendly representation of the cards in the dealer's hand
     *   
     ****************************************************************/
	 
	 void OutputDealerCards();
	 
	 /****************************************************************
     * Name: OutputLast()
     * Preconditions: 
     * Postconditions: Outputs the last card in the selected vector
     *   
     ****************************************************************/
	 void OutputLast();
	 
	 /****************************************************************
     * Name: ReturnHandValue()
     * Preconditions: none.
     * Postconditions: Returns an int value of all of the cards in a player's hand
     *   
     ****************************************************************/
	int ReturnHandValue();
	
	/****************************************************************
	* Name: CheckAces()
	*   
	* Preconditions:
	* Postconditions: Checks the player's hand for any aces and changes their value to 1
	*   
	****************************************************************/
	bool CheckAces();
	
	 /****************************************************************
	* Name: GetBlackjack()
	*   
	* Preconditions:
	* Postconditions: Checks the current hand for blackjack
	*   
	****************************************************************/
	bool GetBlackjack();
	 
	/****************************************************************
	* Name: ClearHand()
	*   
	* Preconditions:
	* Postconditions: Clears the player's hand vector
	*   
	****************************************************************/
	void ClearHand();
	
  private:
	 int m_handValue;
	 int m_handSize;
	 int m_blackjackValue;
	 Card m_tempCard;
	 int m_tempValue;
	 int m_cardsLeft;
	 int firstCard;
	 std::vector<int>m_cardValue;
	 std::vector<Card>m_hand;
};
	 
#endif