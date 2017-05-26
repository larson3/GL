#include "Memo.h"

using namespace std;

	Memo::Memo()
	{
	m_subjectLine = "";
	m_primary = "";
	m_distList = "";
	}
	
	Memo::Memo(int ID, string author, string subject, string recipientName, string distributionList, string textBody) 
	: Document(ID, author, textBody,DOC_TYPE_MEMO)
	{
		
		m_subjectLine = subject;
		m_primary = recipientName;
		m_distList = distributionList;

		
	}
	
	void Memo::DisplayHeader()
	{
		cout << "Document# " << GetID() << endl << "Author: " << GetAuthor() << endl << "Title: " << m_subjectLine << endl;
		cout << "Recipient: " << m_primary << endl << "Distribution List:" << endl << m_distList << endl;
		
	}