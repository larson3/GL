#include "Report.h"

using namespace std;

	Report::Report()
	{
	m_subjectLine = "";
	}
	
	Report::Report(int ID, string author, string subject,string textBody) 
	: Document(ID, author, textBody,DOC_TYPE_REPORT)
	{
		
		m_subjectLine = subject;

		
	}
	
	void Report::DisplayHeader()
	{
		cout << "Document# " << GetID() << endl << "Author: " << GetAuthor() << endl << "Title: " << m_subjectLine << endl <<endl;;
		
	}