#include <cstdlib>
#include "Fraction.h"


using namespace std;

Fraction::Fraction()
{
	m_wholeNum=0;
	m_numerator=0;
	m_denominator=1;
	m_negFlag=false;
	
}

Fraction::Fraction(bool negFlag,int whole,int numerator,int denominator)
{
	
	m_wholeNum = whole;
	m_numerator = numerator;
	m_denominator = denominator;
	m_negFlag = negFlag;
	
}

int Fraction::GetGreatestDivisor(int x,int y) const
{
	int remainder;
	//testing to see if the second int is higher than the first
	if (y>x)
	{
		//if it is we perform a swap
		int tempNum = x;
		x=y;
		y=tempNum;
	}
	
	while (remainder!=0)
	{
		//looping through until we find a remainder of 0
		remainder = x % y; 
		if (remainder!=0)
		{
			x=y;
			y=remainder;
		}
	}
	//returning the value which gave us 0, which is the GCD
	return y;
}
int Fraction::GetLeastMult(int x, int y, int gcd) const
{
	int lcm;
	lcm = (x*y)/gcd;
	return lcm;
}

int Fraction::GetWhole() const
{
	return m_wholeNum;
}
	
int Fraction::GetNumerator() const
{
	return m_numerator;
}
	
int Fraction::GetDenominator() const
{
	return m_denominator;
}

void Fraction::SetDenominator(int denominator)
{
	m_denominator = denominator;
}

bool Fraction::GetFlag() const
{
	return m_negFlag;
}

void Fraction::SetNegative(int &signChange)
{
	signChange*=(-1);
}

void Fraction::NormalizeFraction()
{
	//Checking to see if we have a negative coming in from addition or subtraction
	if (m_numerator < 0)
	{
		m_numerator *= (-1);
		m_negFlag = true;
	}
	//Same as above
	if (m_denominator < 0)
	{
		m_denominator *= (-1);
		m_negFlag = true;
	}
	//This is just a failsafe in case the first two cases somehow miss
	if (m_numerator < 0 && m_denominator < 0 )
	{
		m_numerator*=(-1);
		m_denominator*=(-1);
		m_negFlag = false;
	}
	
	if (m_numerator != 0)
	{
		int theGCD = GetGreatestDivisor(m_numerator,m_denominator);
		//Making sure we don't divide by 0
		if (theGCD!=0)
		{
			//making sure we don't get a 0 in numerator or denominator from division
			if (theGCD <= m_denominator && theGCD <= m_numerator)
				{
				
				m_denominator/=theGCD; 
				m_numerator/=theGCD;
				}
		
		}
		//Normalizing a negative number
		if (m_numerator>0)
	{			
			m_wholeNum=m_numerator/m_denominator;
			m_numerator=m_numerator%m_denominator;
	}
	//Normalizing a negative number and changing its sign
	else if (m_numerator < 0)
		{
			m_wholeNum=m_numerator/m_denominator;
			m_numerator=m_numerator%m_denominator;
			
		//getting rid of the negative sign in front of the numerator
		SetNegative(m_numerator);
	}
	if (m_numerator == 0 )
	{
		m_denominator = 1;
	}
}
}
	
// Overloaded + operator as member function
const Fraction Fraction:: operator+ (const Fraction& rhs) const
{
	Fraction tempValue;
	int theGCD;
	int theLCM;
	
	int leftNum;
	int rightNum;
	int tempNum1;
	int tempNum2;
		
	//changing the mixed number into a simple fraction
	leftNum = m_numerator + m_wholeNum*m_denominator;
	rightNum = rhs.m_numerator + rhs.m_wholeNum * rhs.m_denominator;
	
	theGCD = GetGreatestDivisor(m_denominator,rhs.GetDenominator());
	theLCM = GetLeastMult(m_denominator,rhs.GetDenominator(),theGCD);
	
	//This is setting negatives and positives to make addition simple
	if (m_negFlag)
	{
		leftNum*=(-1);
	}
	if (rhs.m_negFlag)
	{
		rightNum*=(-1);
	}
	//Setting proper denominators and changing numerators proportionally
	tempNum1 =(theLCM/m_denominator*leftNum);
	
	tempNum2 =(theLCM/rhs.m_denominator*rightNum);
	
	tempValue.m_numerator = tempNum1 + tempNum2;
	
	tempValue.m_denominator = theLCM;
	
	tempValue.NormalizeFraction();
	
	return tempValue;
}
// Overloaded minus operator as member function 
const Fraction Fraction:: operator-(const Fraction& rhs) const
{
Fraction tempValue;
	int theGCD;
	int theLCM;
	
	int leftNum;
	int rightNum;
	int tempNum1;
	int tempNum2;
		
	//changing the mixed number into a simple fraction
	leftNum = m_numerator + m_wholeNum*m_denominator;
	rightNum = rhs.m_numerator + rhs.m_wholeNum * rhs.m_denominator;
	
	theGCD = GetGreatestDivisor(m_denominator,rhs.GetDenominator());
	theLCM = GetLeastMult(m_denominator,rhs.GetDenominator(),theGCD);
	//Beginning to add the thing together

	if (m_negFlag)
	{
		leftNum*=(-1);
	}
	if (rhs.m_negFlag)
	{
		rightNum*=(-1);
	}
	tempNum1 =(theLCM/m_denominator*leftNum);
	tempNum2 =(theLCM/rhs.m_denominator*rightNum);
	tempValue.m_numerator = tempNum1 - tempNum2;
	tempValue.m_denominator = theLCM;

	tempValue.NormalizeFraction();
	return tempValue;
}
	
// Overloaded * operator as member function
const Fraction Fraction:: operator* (const Fraction& rhs) const
{
	Fraction tempValue;
	int leftNum;
	int rightNum;
	
	//changing the mixed number into a simple fraction
	leftNum = m_numerator + m_wholeNum*m_denominator;
	rightNum = rhs.m_numerator + rhs.m_wholeNum * rhs.m_denominator;
	
	tempValue.m_numerator = (m_numerator+(m_wholeNum*m_denominator)) * (rhs.GetNumerator()+(rhs.GetWhole()*rhs.GetDenominator()));
	tempValue.m_denominator = m_denominator * rhs.GetDenominator();
	
	if ( m_negFlag != rhs.m_negFlag)
		tempValue.m_negFlag = true;
	tempValue.NormalizeFraction();
	return tempValue;
}

// Overloaded  / operator as member function 
const Fraction Fraction:: operator/(const Fraction& rhs) const
{
	Fraction tempValue;
	int leftNum;
	int rightNum;
	
	//changing the mixed number into a simple fraction
	leftNum = m_numerator + m_wholeNum*m_denominator;
	rightNum = rhs.m_numerator + rhs.m_wholeNum * rhs.m_denominator;
	//For some unknown reason this print statement fixes a division bug.
	//cout<<"";
	tempValue.m_numerator = leftNum * rhs.m_denominator;
	tempValue.m_denominator = m_denominator * rightNum;
	
	if (tempValue.m_denominator == 0)
	{
		cout<<"Cannot accept denominator of zero, exiting program."<<endl;
			exit(0);
	}
	if ( m_negFlag != rhs.m_negFlag)
		tempValue.m_negFlag = true;
	tempValue.NormalizeFraction();
	return tempValue;
}


ostream & operator << (ostream& out, Fraction userNum)
{
	int wholeNum = userNum.GetWhole();
	int numerator = userNum.GetNumerator();
	int denominator = userNum.GetDenominator();
	bool flag = userNum.GetFlag();
	
	if (denominator == 0)
		{
			cout<<"Cannot accept denominator of zero, exiting program."<<endl;
			exit(0);
			
		}
	//testing for a zero, making sure it has no negative
	if (numerator == 0 && wholeNum == 0 )
	{
		flag = false;
	}
		//making it look negative if the negflag persists
		if (flag)
			return (out<< "-" <<wholeNum << "&" << numerator << "/" << denominator);	
		else
			return (out<< wholeNum << "&" << numerator << "/" << denominator);	
}

