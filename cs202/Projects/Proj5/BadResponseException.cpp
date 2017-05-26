#include <iostream>
#include "BadResponseException.h"

using namespace std;

	BadResponseException::BadResponseException(){}

	BadResponseException::BadResponseException(string parameter)
	{
		m_message = parameter;
	}
	
	string BadResponseException::GetMessage()
	{
		return m_message;
	}

