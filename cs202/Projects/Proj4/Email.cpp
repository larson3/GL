#include "Email.h"

using namespace std;

	Email::Email()
	{
	m_subjectLine = "";
	m_primary = "";
	m_recipEmail = "";
	}
	
	Email::Email(int ID,string author,string subject,string recipientName, string recipientEmail,string textBody) 
	: Document(ID, author, textBody,DOC_TYPE_EMAIL)
	{
		
		m_subjectLine = subject;
		m_primary = recipientName;
		m_recipEmail = recipientEmail;

	}
	void Email::DisplayHeader()
	{
		cout << "Document# " << GetID() << endl << "Author: " << GetAuthor() << endl << "Title: " << m_subjectLine << endl;
		cout << "Recipient: " << m_primary << endl << "Recipient Email: " << endl << m_recipEmail << endl;
		
	}