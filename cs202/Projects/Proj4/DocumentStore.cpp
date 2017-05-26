#include <cstdlib>
#include <iostream>
#include <string>

#include "DocumentStore.h"
#include "Email.h"
#include "Memo.h"
#include "Report.h"

using namespace std;

DocumentStore::DocumentStore() : m_nextID(10001) {}

string DocumentStore::InputText(const char *prompt) {
    string input;

    cout << prompt;
    getline(cin, input);
    return input;
}

string DocumentStore::InputMultilineText(const char *prompt) {
    string input, nextLine;
    bool endSeen = false;

    cout << prompt << "(type END on separate line to stop):\n";
    do {
	getline(cin, nextLine);
	if (nextLine.compare("END") == 0) {
	    endSeen = true;
	}
	else {
	    input.append(nextLine + "\n");
	}
    } while (!endSeen);
    return input;

}

void DocumentStore::CreateMemo(){
    Memo *newMemoPtr;
    string author, subject, recipientName, distributionList, textBody;

    author = InputText("Enter author:\n");
    subject  = InputText("Enter subject:\n");
    recipientName = InputText("Enter recipient:\n");
    distributionList = InputMultilineText("Enter distribution list ");
    textBody = InputMultilineText("Enter text body ");
    newMemoPtr = new Memo(m_nextID++, author, subject, recipientName,
	  distributionList, textBody);
    cout << "Memo #" << newMemoPtr->GetID()  // Verification of ID
	 << " entered into documents list.\n";
    m_active.push_back(newMemoPtr);
}

void DocumentStore::CreateEmail(){
    Email *newEmailPtr;
    string author, subject, recipientName, recipientEmail, textBody;
	author = InputText("Enter author:\n");
    subject  = InputText("Enter subject line:\n");
    recipientName = InputText("Enter recipient:\n");
    recipientEmail = InputMultilineText("Enter recipient Email: ");
    textBody = InputMultilineText("Enter text body ");
    newEmailPtr = new Email(m_nextID++, author, subject, recipientName,
	  recipientEmail, textBody);
    cout << "Email #" << newEmailPtr->GetID()  // Verification of ID
	 << " entered into documents list.\n";
    m_active.push_back(newEmailPtr);
	}

void DocumentStore::CreateReport(){
	//this is much shorter, as reports are short
    Report *newReportPtr;
    string author, title, subject, textBody;
	author = InputText("Enter author:\n");
    subject  = InputText("Enter title:\n");
    textBody = InputMultilineText("Enter text body ");
    newReportPtr = new Report(m_nextID++, author, subject,textBody);
    cout << "Report #" << newReportPtr->GetID()  // Verification of ID
	 << " entered into documents list.\n";
    m_active.push_back(newReportPtr);
	}



void DocumentStore::Display(int docID){
    Document *doc = NULL;
    for (int i = 0; i < m_active.size(); i++) {
	if (m_active[i]->GetID() == docID) {
	    doc = m_active[i];
	    break;
	}
    }
    if (doc != NULL) {
	if (doc->GetType() == DOC_TYPE_EMAIL) {
	    Email *email = static_cast<Email *>(doc);
	    email->DisplayHeader();
	    email->DisplayBody();
	}
	else if (doc->GetType() == DOC_TYPE_MEMO) {
	   Memo *memo = static_cast<Memo *>(doc);
	   memo->DisplayHeader();
	   memo->DisplayBody();
	}
	else if (doc->GetType() == DOC_TYPE_REPORT) {
	    Report *report = static_cast<Report *>(doc);
	    report->DisplayHeader();
	    report->DisplayBody();
	}
	else {
	    cout << "Unknown/unexpected document type?\n";
	    exit(1);
	}
    }
    else {
	cout << "Document #" << docID << " not found.\n";
    }
}




void DocumentStore::ListDocuments(){

    Document *doc = NULL;
	cout<<"Document List: "<<endl;
	if (m_active.size()!=0)
	//we skip the compare between ids and just print them all
	{
    for (int i = 0; i < m_active.size(); i++) {
	    doc = m_active[i];
		
		if (doc->GetType() == DOC_TYPE_EMAIL) {
			Email *email = static_cast<Email *>(doc);
			//obviously we cut out the body
			email->DisplayHeader();
			
		}
		else if (doc->GetType() == DOC_TYPE_MEMO) {
			Memo *memo = static_cast<Memo *>(doc);
			memo->DisplayHeader();
		
		}
		else if (doc->GetType() == DOC_TYPE_REPORT) {
			Report *report = static_cast<Report *>(doc);
			report->DisplayHeader();
			
		}
		else {
			cout << "Unknown/unexpected document type?\n";
			exit(1);
			}
		}
		}
		else
		{
		cout<<"No documents found"<<endl;
		}
		
	}

void DocumentStore::Search(string queryStr){
    //in case the word is not present
	bool found = false;
    for (int i = 0; i < m_active.size(); i++) {
	
	   
		string temp = m_active[i]->GetBody();
		//searching for the word, if not found it returns npos
	    if(temp.find(queryStr)!=std::string::npos)
			{
			cout<<m_active[i]->GetID()<<endl;
			//setting found to true so we do not lie to the user
			found = true;
			}
		}
		if(found == false)
		{
		cout<<"No documents found."<<endl;
		}
	
}

void DocumentStore::ClearDocuments(){
    Document *doc;

    for (int i = 0; i < m_active.size(); i++) {
    	doc = m_active[i];
	if (doc->GetType() == DOC_TYPE_EMAIL) {
	    Email *email = static_cast<Email *>(doc);
	    delete email;
	}
	else if (doc->GetType() == DOC_TYPE_MEMO) {
	    Memo *memo = static_cast<Memo *>(doc);
	    delete memo;
	}
	else if (doc->GetType() == DOC_TYPE_REPORT) {
	    Report *report = static_cast<Report *>(doc);
	    delete report;
	}
	else {
	    cout << "Unknown/unexpected document type?\n";
	    exit(1);
	}
	m_active[i] = NULL;
    }
    m_active.clear();
    cout << "Document collection has been cleared\n";
}
