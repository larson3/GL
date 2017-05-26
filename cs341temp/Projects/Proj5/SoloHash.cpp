#include "SoloHash.h"

//basically a bunch of setters and getters for use in ReadData
SoloHash::SoloHash(){}

SoloHash::~SoloHash()
{
	//m_hashTable.makeEmpty();
}

void SoloHash::setWord(string word)
{
	m_hashTable.insert(word);
}


string SoloHash::getName()
{
	return m_name;
}

void SoloHash::setName(string name)
{
	m_name = name;
}

HashTable<string> SoloHash::getHash()
{
	//returns a container!  Didn't know this was possible previously
	return m_hashTable;
}

bool SoloHash::getHash(string test)
{
	//cout<<m_hashTable.contains(test)<<endl;
	return m_hashTable.contains(test);
}