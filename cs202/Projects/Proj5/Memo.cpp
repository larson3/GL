#include <iostream>
#include <string>
#include <vector>
#include "Memo.h"

using namespace std;

Memo::Memo(int aID, string author, string subject, string recipientName,
	   vector<string> distributionList, string textBody)
    : Correspondence(aID, author, textBody, subject, recipientName),
      m_distributionList(distributionList) {
}

vector<string> Memo::GetDistributionList() {
    return m_distributionList;
}

void Memo::DisplayHeader() {
    vector<string> distList;

    cout << "Document #: " << GetID() << endl;
    cout << "Author: " << GetAuthor() << endl;
    cout << "Subject: " << GetSubject() << endl;
    cout << "Recipient: " << GetRecipientName() << endl;
    cout << "Distribution List:\n";
    distList =  GetDistributionList();
    for (unsigned int i = 0; i < distList.size(); i++) {
	cout << "  " << distList[i] << endl;
    }
}

Memo *Memo::CreateResponse(string author, string textBody, int nextID) {

string responseAuthor=GetAuthor();

bool foundAuthor=false;
for(unsigned int x=0;x<m_distributionList.size();x++)
{
	if(m_distributionList[x]==author)
	{
		
		foundAuthor = true;
		
		
		//Making a new distribution list.  As making changes to the old
		//list will change the values for the previous memo.
		vector<string> newDistributionList;
		for(unsigned int x=0;x<m_distributionList.size();x++)
		{
		//This code will switch the author's name with the recipient's name
		// in the new dist list
			if(m_distributionList[x]==author)
			{
				newDistributionList.push_back(GetRecipientName());
			}
			//ever other name needs to stay the same
			else{
				newDistributionList.push_back(m_distributionList[x]);
				}
		}
	return new Memo(nextID, author, "RE: " + GetSubject(), responseAuthor, 
		newDistributionList, textBody);

	}
		
	}

if(GetRecipientName()!=author && foundAuthor == false)
	//If the author was not someone who is allowed to respond
	{
		throw BadResponseException("Non-recipients cannot respond");
	}
	//this one is for if the author is the original recipient
	else{
		return new Memo(nextID, author, "RE: " + GetSubject(), responseAuthor, 
		GetDistributionList(), textBody);
	}

}
