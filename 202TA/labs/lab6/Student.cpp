#include "Student.h"

Student::Student()
{
	int newGPA;
	cout<<"Enter total number of students"<<endl;
	cin >> m_num;
	m_ptr = new float[m_num];
	for(int x = 0;x<m_num;x++)
	{
		cout<<"Enter GPA of students"<<endl;
		cin >> newGPA;
		m_ptr[x] = newGPA;
	}
}

Student::~Student()
{
	delete [] m_ptr;
}

void Student::Display()
{
	for(int x = 0;x<m_num;x++)
	{
		cout<<"GPA for Student "<<x<<" is: "<<m_ptr[x]<<endl;
	}
}