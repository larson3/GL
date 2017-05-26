
#include "SeismicDataCollector.h"


using namespace std;

SeismicDataCollector::SeismicDataCollector(){};

void SeismicDataCollector::readFile(string inFile)
{
	ifstream fileName(inFile.c_str(), ios_base::in);
	
	string rel;
	string waste;
	string line;
	stringstream ss;
	int count =0;

	//this is to skip the useless first line of text
	fileName.ignore(500,'\n');
	
	//starting the parse by splitting by /n
	while(getline(fileName, line))
	{
		ss << line;
		
		//taking the parsed stringstream object and splitting by commas
		while(getline(ss,rel,','))
		{
			//switch since up until word 13 the commas as constant
			switch(count)
			{
				case 0:
					temptime = rel;
					count++;
					break;
				case 1:
					templatitude = rel;
					count++;
					break;
				case 2:
					templongitude = rel;
					count++;
					break;
				case 3:
					tempdepth = rel;
					count++;
					break;
				case 4:
					tempmag = rel;
					count++;
					break;
				case 5:
					
					tempmagType =whichMagType(rel);
					
					count++;
					break;
				case 6:
					
					count++;
					break;
				case 7:
					count++;
					break;
				case 8:
					
					count++;
					break;
				case 9:
					
					count++;
					break;
				case 10:
					
					count++;
					break;
				case 11:
					
					count++;
					break;
					
				//here's where things get weird
				case 12:
		
					{
					//sometimes there's no quotation marks
					
					getline(ss,waste,'\"');
					//this checks to see if there's an empty string in
					//waste, if so it will just take the remainder of the line
					if(waste.size()!=0)
					{
						stringstream ss(waste);
						int check=0;
						//now splitting the remaining words by comma
						while(getline(ss,rel,','))
						{
							switch(check)
							{
								case 0:
									tempplace = rel;
									
									check++;
									break;
								case 1:
									temptype=whichType(rel);
				
									check=0;
									break;
							}
						
						}
		
						count=0;
					}
					else
					{
					//this is if there were quotation marks, meaning
					//that there's at least a city and state
					getline(ss,tempplace,'\"');
					getline(ss,waste,',');
					count++;
					}
					break;
					
					}
				case 13:

					{
					//in case everything is not stupid, we take the 
					//type here
					temptype=whichType(rel);
					count=0;
				
					}
					break;


			}
			
		}
		ss.clear();

		//this switch statement creates a bunch of different object types
		switch(temptype)
		{
			case 0:
			{
				//for example here is an acousticnoise object being created
	
				AcousticNoise newObject(temptime,templatitude,templongitude,tempmag,tempplace);
				newObject.setMagType(tempmagType);
				newObject.setType(temptype);
				acousticNoiseVector.push_back(newObject);
				//printing that object man!
				cout<<newObject<<endl;
				//we then write the contents of that object to an out file
				//	writeResultingData(newObject);
				break;
			}
			case 1:
			{
				//it's the same for all the cases
				AnthropogenicEvent newObject(temptime,templatitude,templongitude,tempmag,tempplace);
				newObject.setType(temptype);
				anthropogenicEventVector.push_back(newObject);
				//cout<<newObject<<endl;
				//writeResultingData(newObject);
				break;
			}
			case 2:
			{
				Explosion newObject(temptime,templatitude,templongitude,tempmag,tempplace);
				newObject.setMagType(tempmagType);
				newObject.setType(temptype);
				explosionVector.push_back(newObject);
				//cout<<newObject<<endl;
				//writeResultingData(newObject);
				break;
			}
			case 3:
			{
				MiningExplosion newObject(temptime,templatitude,templongitude,tempmag,tempplace);
				newObject.setType(temptype);
				miningExplosionVector.push_back(newObject);
				//cout<<newObject<<endl;
				//newObject.writeResultingData();
				break;
			}
			case 4:
			{
				QuarryBlast newObject(temptime,templatitude,templongitude,tempmag,tempplace);
				newObject.setType(temptype);
				quarryBlastVector.push_back(newObject);
				//cout<<newObject<<endl;
				//writeResultingData(newObject);
				break;
			}
			case 5:
			{
				Earthquake newObject(temptime,templatitude,templongitude,tempmag,tempplace,tempdepth);
				newObject.setMagType(tempmagType);
				newObject.setType(temptype);
				earthquakeVector.push_back(newObject);
				//cout<<newObject<<endl;
				//writeResultingData(newObject);
				break;
			}
		}
	}	
	//let's close this file now so that no feelings are hurt
	fileName.close();
	writeResultingData();
}

string SeismicDataCollector::getFileName()
{
	return m_fileName;
}

bool SeismicDataCollector::setFileName(string fileName)
{
	m_fileName = fileName;
	return true;
}

void SeismicDataCollector::writeResultingData()
{
	
	for(unsigned int i=0;i<earthquakeVector.size();i++)
	{
		ofstream outFile("resultsEarthquake.txt",ios::app);
		outFile<<earthquakeVector[i];
		cout<<earthquakeVector[i];
		outFile.close();
	}
	
	for(unsigned int i=0;i<quarryBlastVector.size();i++)
	{
		ofstream outFile("resultsQuarryBlast.txt",ios::app);
		outFile<<quarryBlastVector[i];
		cout<<quarryBlastVector[i];
		outFile.close();
	}
	
	for(unsigned int i=0;i<explosionVector.size();i++)
	{
		ofstream outFile("resultsExplosion.txt",ios::app);
		outFile<<explosionVector[i];
		cout<<explosionVector[i];
		outFile.close();
	}
	
	for(unsigned int i=0;i<acousticNoiseVector.size();i++)
	{
		ofstream outFile("resultsAcousticNoise.txt",ios::app);
		outFile<<acousticNoiseVector[i];
		cout<<acousticNoiseVector[i];
		outFile.close();
	}
	
	for(unsigned int i=0;i<anthropogenicEventVector.size();i++)
	{
		ofstream outFile("resultsAnthropogenicEvent.txt",ios::app);
		outFile<<anthropogenicEventVector[i];
		cout<<anthropogenicEventVector[i];
		outFile.close();
	}
	
	for(unsigned int i=0;i<miningExplosionVector.size();i++)
	{
		ofstream outFile("resultsMiningExplosion.txt",ios::app);
		outFile<<miningExplosionVector[i];
		cout<<miningExplosionVector[i];
		outFile.close();
	}
	
}

magTypeNum SeismicDataCollector::whichMagType(string magType)
{
	//returning a magTypeNum to help with switch statements
	if (magType=="md")
	{
		return md;
	}
	//we take in a string because the parser will return a string
	else if(magType=="ml")
	{
		return ml;
	}
	else
	{
		return mb_lg;
	}
}

typeNum SeismicDataCollector::whichType(string type)
{
	//see above, same deal
	if(type=="earthquake")
	{
		return earthquake;
	}
	else if(type=="acoustic noise")
	{
		return acoustic_noise;
	}
	else if(type=="anthropogenic event")
	{
		return anthropogenic_event;
	}
	else if(type=="explosion")
	{
		return explosion;
	}
	else if(type=="mining explosion")
	{
		return mining_explosion;
	}
	else
	{
		return quarry_blast;
	}
}
