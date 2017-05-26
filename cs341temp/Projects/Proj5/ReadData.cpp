#include "ReadData.h"

ReadData::ReadData(){}

ReadData::~ReadData()
{
	//m_intersection.makeEmpty();
	//m_union.makeEmpty();
}

void ReadData::toLower(basic_string<char>& s)
{
	//we are iterating through the char array and making each individual
	//letter lowercase, passing by reference
	for (basic_string<char>::iterator p = s.begin();
		p != s.end(); ++p)
	{
		*p = tolower(*p);
	}
}


void ReadData::openDirectory(char const *dir_name)
{

	DIR *dir;
	struct dirent *entry;
	struct stat info;
	
	//open
	dir = opendir(dir_name);
	if(!dir)
	{
		cout<<"Not a valid path"<<endl;
		return;
	}
	
	
	//reading the files one by one
	while( (entry = readdir(dir)) != NULL)
	{
		if(entry->d_name[0] != '.')
		{
			string path = string(dir_name) + "/" + string(entry->d_name);
			
			stat((char*)path.c_str(),&info);
			if(S_ISDIR(info.st_mode))
			{
				openDirectory((char*)path.c_str());
			}
			ifstream testFile(path.c_str(), ios_base::in);
			SoloHash newHash;
			newHash.setName(entry->d_name);
			//parsing begins with newlines, then by whitespace
				while(getline(testFile,line,'\n'))
				{
					ss<<line;

					while(getline(ss,rel,' '))
					{
					
						//then we lowercase the word
						toLower(rel);
						//and throw out all punctuation
						for(unsigned int i=0;i<rel.size();i++)
						{
							char c = rel[i];
							int x = c;
							if(x>=97 and x<=122)
							{
								temp += rel[i];
								
							}
							
						}
						if(temp != "")
						{
						//adding the word to the hash
							
							if (!newHash.getHash(temp))
							{
								newHash.setWord(temp);
							}
												
						}
						//and reset temp to an empty string
						temp = "";
						
					}
					ss.clear();
				}
			//adding the hashtable to the hash vector
			hashList.push_back(newHash);

			}
	}
	closedir(dir);

}

void ReadData::calculateJaccard()
{
	if( remove( "results.txt" ) != 0 )
	{
		cout<<"";
	}
	else
	{
		cout<<"";
	}
	
	this->m_highestNum = 0;
	//creating a new output object and writing to it
	ofstream outFile("results.txt", ios::app);
	//comparing each file to each file exactly once
	for(unsigned int x=0;x<hashList.size();x++)
	{		
		for(unsigned int i=x;i<hashList.size();i++)
		{
			compare(hashList[x],hashList[i],outFile);
		}

	}
	//writing the most similar from all the comparisons
	outFile<<"Most similar: \""<<this->m_highestPairA<<" , "<<this->m_highestPairB<<"\""<<endl;
	outFile.close();
}

void ReadData::compare(SoloHash a, SoloHash b, ostream &out)
{
	float intersectionSize, unionSize;
	float jaccardTotal;
	//We only compare if the plays are not the same name
	//the same plays are... well... the same
	if(strcmp(a.getName().c_str(),b.getName().c_str())!=0)
	{
		HashTable<string> hash1 = a.getHash();
		HashTable<string> hash2 = b.getHash();

		int size1= hash1.getSize();
		int size2 = hash2.getSize();
		//looping through the hash table, only taking the active words
		for(int i=0;i<size1;i++)
		{
			string newWord = hash1.getWord(i);
			//only accept if it is not the trash string
			if(strcmp("thisisnotintheplays",newWord.c_str())!=0)
			{
				//if the word is present in both, it must be in the
				//intersection and the union
				if(hash2.contains(newWord))
				{
					m_intersection.insert(newWord);
					m_union.insert(newWord);

				}
				//otherwise it is only present in the union
				else
				{					
					m_union.insert(newWord);
				}
			}
		}
		//the same process, but compare b to a
		for(int i=0;i<size2;i++)
		{
			string newWord = hash2.getWord(i);
			if(strcmp("thisisnotintheplays",newWord.c_str())!=0)
			{
				if(hash1.contains(newWord))
				{
					m_intersection.insert(newWord);
					m_union.insert(newWord);
				}
				else
				{					
					m_union.insert(newWord);
				}
			}
		}
	}
	//getting the size of all the active nodes of the hash tables
	intersectionSize = m_intersection.trueSize();
	unionSize = m_union.trueSize();

	//writing results to file
	if (unionSize != 0)
	{
		jaccardTotal = intersectionSize/unionSize;
		out<<"J\"("<<a.getName()<<"\",\""<<b.getName()<<"\") = "<<jaccardTotal<<endl;
		
		if(jaccardTotal > this->m_highestNum)
		{
			//here we are storing the most similar plays
			//this is constantly being checked and updated
			this->m_highestNum = jaccardTotal;
			this->m_highestPairA = a.getName();
			this->m_highestPairB = b.getName();
		}
	}
	else
	{
		out<<"J\"("<<a.getName()<<"\",\""<<b.getName()<<"\") = 1.0"<<endl;
	}
	
	//clear out the hash tables for the next iteration
	m_intersection.makeEmpty();
	m_union.makeEmpty();

}
