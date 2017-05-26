#include <cstdlib>
#include "Document.h"
#include "Memo.h"
using namespace std;


	Document::Document(){}

	Document::Document(int ID, string author, string textBody,int type)
	{
		m_ID = ID;
		m_author = author;
		m_body = textBody;
		m_type = type;
	}
	
	int Document::GetType()
	{
		return m_type;
	}
	
	string Document::GetAuthor()
	{
		return m_author;
	}
	
	string Document::GetBody()
	{
		return m_body;
	}
	
	int Document::GetID()
	{
		return m_ID;
	}	
	
	void Document::DisplayHeader()
	{
		cout << m_ID << endl << m_author << endl;
	}
	
	void Document::DisplayBody()
	{
		cout<< m_body<<endl;
	}
	