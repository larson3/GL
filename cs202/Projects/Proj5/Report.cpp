#include <iostream>
#include "Report.h"

using namespace std;

Report::Report(){}
Report::Report(int aID, string author, string title, string textBody)
    : Document(aID, author, textBody), m_title(title) {
}

string Report::GetTitle() {
    return m_title;
}

void Report::DisplayHeader() {
	
    cout << "Document #: " << GetID() << endl;
    cout << "Author: " << GetAuthor() << endl;
    cout << "Title: " << GetTitle() << endl;
}

Report *Report::CreateResponse(string author, string textBody, int nextID) {
	//The user can't respond to a report -- silly user!
	throw BadResponseException("It is illegal to respond to a report.");
	return NULL;
	}
    
Report::~Report()
{
}
