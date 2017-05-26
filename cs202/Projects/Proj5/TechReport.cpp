#include <iostream>
#include <string>
#include "TechReport.h"

using namespace std;

TechReport::TechReport(){}

TechReport::TechReport(int aID, string author, string title, string textBody)
    : Report(aID, author, title, textBody) {
}

TechReport *TechReport::CreateResponse(string author, string textBody, int nextID)
{
	//Creating a new comment and adding it to our vector
	Comment newComment(author,textBody);
	m_comments.push_back(newComment);

	return NULL;
}

void TechReport::DisplayBody()
{
	cout << "Contents:\n";
    cout << GetBody()<<endl;
	//default no comment message
	if(m_comments.size()==0)
		{
			cout<<"--No comments yet."<<endl;
		}
	else{
		//looping through each comment object
		for(unsigned int x=0;x<m_comments.size();x++)
		{
			//I thought that overloading this was unnecessary, as it gets used once
			int currentNum = x+1;
			cout<<"Comment "<<currentNum<<" by ";
			cout<<m_comments[x].m_author<<":"<<endl;;
			cout<<m_comments[x].m_textBody<<endl;
		}
	}
}

bool TechReport::Search(string searchString) {
    string textBody = GetBody();
   //Searching through the comments for a match.
   //We only return if we find one.
    for(unsigned int x=0;x<m_comments.size();x++)
	{
		if (m_comments[x].m_textBody.find(searchString) != string::npos)
		{
		return m_comments[x].m_textBody.find(searchString);
		}
	}
	//otherwise we continue on to the main body and return
   return  textBody.find(searchString) != string::npos;

	
	//failsafe to prevent warnings
	return true;
	
	}

