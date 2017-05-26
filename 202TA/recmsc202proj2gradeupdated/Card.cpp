/*****************************************
  ** File:    Card.cpp
  ** Project: CMSC 202 Project 2, Spring 2017
  ** Author:  Daniel Lee
  ** Date:    3/9/2017
  ** Section: 13
  ** E-mail:  danlee1@umbc.edu
  **  
  ** This file implements the Card class.
  *****************************************/

#include <iostream>
#include <string>

#include "Card.h"

//// Constructors ////
// default constructor
Card::Card() {}

Card::Card(int cardNum, string cardDesc) {
  m_type = cardNum;
  m_desc = cardDesc;
}

//// Accessors ////
int Card::GetType() {
  return m_type;
}

string Card::ToString() {
  return m_desc;
}

//// Helper Methods ////
