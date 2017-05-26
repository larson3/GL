#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int nextPrime( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
  public:
    explicit HashTable( int size = 101 ) : array( nextPrime( size ) )
      { makeEmpty( ); }


	 ~HashTable()
	 {
		
	 }
/****************************************************************
 * trueSize():
 * Preconditions: 
 *	  valid hash table array
 * Postconditions:
 *   Will count the number of active nodes in the heap
 ****************************************************************/	  
	int trueSize()
	{
		int count = 0;
		for(unsigned int i = 0; i < array.size( ); i++ )
		{
			if(array[i].info==0)
			{
				count++;
			}
		}
		return count;
	}
	
	void printAll()
	{
		for(unsigned int i = 0; i < array.size( ); i++ )
		{
			if(array[i].info==0)
			{
				cout<<array[i].element<<endl;
			}
		}
	}
	
    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    void makeEmpty( )
    {
        currentSize = 0;
        for(unsigned int i = 0; i < array.size( ); i++ )
            array[ i ].info = EMPTY;
    }

    bool insert( const HashedObj & x )
    {
            // Insert x as active
        unsigned int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        array[ currentPos ] = HashEntry( x, ACTIVE );

            // Rehash; see Section 5.5
        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

	
/****************************************************************
 * getSize():
 * Preconditions: 
 *	  valid hash table array
 * Postconditions:
 *   Returns the size of the entire array
 ****************************************************************/
	int getSize()
	{
		return array.size();
	}


/****************************************************************
 * getWord():
 * Preconditions: 
 *	  valid hash table array and int within the array bounds
 * Postconditions:
 *   Returns the word at the selected position.  If it is an active
 *	 node it will return the word housed there.  Otherwise returns
 *	 garbage which is meant to never match anything in either play.
 ****************************************************************/	
	string getWord(int currentPos)
	{
		if(array[currentPos].info==ACTIVE)
		{
			return array[currentPos].element;
		}
		else
		{
			return "thisisnotintheplays";
		}
	}

    enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
          : element( e ), info( i ) { }
    };
    
    vector<HashEntry> array;
    unsigned int currentSize;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x ) const
    {
        int offset = 1;
        unsigned int currentPos = myhash( x );

          // Assuming table is half-empty, and table length is prime,
          // this loop terminates
        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    void rehash( )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for(unsigned int j = 0; j < array.size( ); j++ )
            array[ j ].info = EMPTY;

            // Copy table over
        currentSize = 0;
        for(unsigned int i = 0; i < oldArray.size( ); i++ )
            if( oldArray[ i ].info == ACTIVE )
                insert( oldArray[ i ].element );
    }
    int myhash( const HashedObj & x ) const
    {
        int hashVal = hash( x );

        hashVal %= array.size( );
        if( hashVal < 0 )
            hashVal += array.size( );

        return hashVal;
    }
};

int hash( const string & key );
int hash( int key );

#endif