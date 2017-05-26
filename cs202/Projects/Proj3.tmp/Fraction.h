/****************************************************************
 * File:    Fraction.h
 * Project: CMSC 202 Project 3, Spring 2014
 * Author:  John Larson
 * Date:    10/29/14
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 *
 ****************************************************************/

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>

using namespace std;

class Fraction
{
  public:
	
	 /****************************************************************
     * Fraction:
     *   default (no-arg) constructor
     * Preconditions: none.
     * Postconditions: returns a fraction 0&0/1;
     ****************************************************************/
	Fraction();
	
	 /****************************************************************
     * Fraction:
     *   Standard constructor
     * Preconditions:
     *   negFlag - flags if the fraction is negative
     *   whole - the whole number
	 *	 numerator - the numerator
	 *   denominator - the denominator
     * Postconditions: constructs a fraction whole&numerator/denominator
     ****************************************************************/
	Fraction(bool negFlag,int whole,int numerator,int denominator);
	
	 /****************************************************************
     * GetGreatestDivisor:
     * Preconditions: 
	 *	  x - first number
	 *	  y - second number
     * Postconditions:
     *   Returns: the greatest divisor of x and y
     ****************************************************************/
	int GetGreatestDivisor(int x,int y) const;
	
	/****************************************************************
     * GetLeastMult:
     * Preconditions:
	 *    x - the first number
	 *    y - the second number
	 *    gcd - the greatest common divisor
     * Postconditions:
     *   Returns: the least common multiple of the two numbers
     ****************************************************************/
	int GetLeastMult(int x, int y, int gcd) const;
	
	/****************************************************************
     * GetWhole:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the fraction's whole number
     ****************************************************************/
	int GetWhole() const;
	
	/****************************************************************
     * GetNumerator:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the fraction's numerator
     ****************************************************************/
	int GetNumerator() const;
	
	/****************************************************************
     * GetDenominator:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the fraction's denominator
     ****************************************************************/
	int GetDenominator() const;
	
	/****************************************************************
     * SetDenominator:
     * Preconditions:
	 * 	  - denominator
     * Postconditions:
     *   Returns: none.
     ****************************************************************/
	void SetDenominator(int denominator);
	
	/****************************************************************
     * GetFlag:
     * Preconditions: none.
     * Postconditions:
     *   Returns: value of m_flag
     ****************************************************************/
	bool GetFlag() const;
	
	/****************************************************************
     * SetNegative:
     * Preconditions:
	 *     - signChange
     * Postconditions:
     *   changes the sign of the number
     ****************************************************************/
	void SetNegative(int &signChange);
	
	/****************************************************************
     * NormalizeFraction:
     * Preconditions: none.
     * Postconditions:
     *   sets the numerator lower than the denominator
	 *	 raises the whole number accordingly
	 *   lowers the numerator and denominator to their lowest value
     ****************************************************************/
	void NormalizeFraction();
		
	
	/****************************************************************
     * operator+:
     * Preconditions:
	 *		- left handed fraction
	 *		- right handed fraction
     * Postconditions:
     *   Returns: the value of the two fractions being added
     ****************************************************************/
    const Fraction operator+ (const Fraction& rhs) const;

	
 	/****************************************************************
     * operator-:
     * Preconditions:
	 *		- left handed fraction
	 *		- right handed fraction
     * Postconditions:
     *   Returns: the value of the two fractions being subtracted
     ****************************************************************/
    const Fraction operator-(const Fraction& rhs) const;
	
	/****************************************************************
     * operator*:
     * Preconditions:
	 *		- left handed fraction
	 *		- right handed fraction
     * Postconditions:
     *   Returns: the value of the two fractions being multiplied
     ****************************************************************/
    const Fraction operator* (const Fraction& rhs) const;

    	/****************************************************************
     * operator/:
     * Preconditions:
	 *		- left handed fraction
	 *		- right handed fraction
     * Postconditions:
     *   Returns: the value of the two fractions being divided
     ****************************************************************/
    const Fraction operator/(const Fraction& rhs) const;
	
  private:
	int m_wholeNum;
	int m_numerator;
	int m_denominator;
	bool m_negFlag;
	bool m_opFlag;
	int m_wholeCarry;
};
	/****************************************************************
     * operator<<:
     * Preconditions:
	 *		- an object of type fraction
     * Postconditions:
     *   Returns: prints the value of the function in x&y/z form
     ****************************************************************/
ostream & operator << (ostream& out, Fraction userNum);

#endif
	