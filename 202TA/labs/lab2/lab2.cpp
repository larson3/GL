#include <iostream>

using namespace std;

double calcAverage(double grades[])
{
	double GPA;
	GPA = (grades[0]+grades[1]+grades[2])/3;
	return GPA;
}

void printGPA(double GPA)
{
	cout<<"Your GPA is: "<<GPA<<endl;
	if(GPA >= 90)
		cout<<"You earned an A"<<endl;
	else if(GPA >= 80)
		cout<<"You earned a B"<<endl;
	else if(GPA >= 70)
		cout<<"You earned a C"<<endl;
	else if(GPA >= 60)
		cout<<"You earned a D"<<endl;
	else
		cout<<"You earned an F"<<endl;
}

int main()
{
	double grades[3];
	double GPA;
	int x;
	for(x=0;x<3;x++)
	{
		cout<<"Enter your score"<<endl;
		cin>>grades[x];
	}
	GPA=calcAverage(grades);
	printGPA(GPA);
	
	return 0;
}