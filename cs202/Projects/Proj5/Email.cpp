#include <iostream>
#include "Email.h"

using namespace std;

Email::Email(int aID, string author, string subject, string recipientName,
	     string recipientEmail, string textBody)
    : Correspondence(aID, author, textBody, subject, recipientName),
      m_recipientEmail(recipientEmail) {
}

string Email::GetRecipientEmail() {
    return m_recipientEmail;
}

void Email::DisplayHeader() {
    cout << "Document #: " << GetID() << endl;
    cout << "Author: " << GetAuthor() << endl;
    cout << "Subject: " << GetSubject() << endl;
    cout << "Recipient: " << GetRecipientName() << endl;
    cout << "E-mail Address: " << GetRecipientEmail() << endl;
}

Email *Email::CreateResponse(string author, string textBody, int nextID) {
	if(author!=GetRecipientName())
	{
		throw BadResponseException("Non-recipients cannot respond");
	}
	else{
		return new Email(nextID, author, "RE: " + GetSubject(), GetAuthor(), 
		GetAuthor() + "@yoyodyne.com", textBody);
	}
}