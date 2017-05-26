#include "Sequencer.h"
#include <typeinfo>

 
 //name: Sequencer (default constructor)
  //pre: A linked list (DNA) is available
  //post: A linked list (DNA) where m_head and m_tail points to NULL
  //      m_size is also populated with SizeOf
Sequencer::Sequencer(string fileName)
{
	m_fileName = fileName;
	readFile();
	cout<<"New Sequencer Loaded"<<endl;
	mainMenu();
}
  //name: Sequencer (destructor)
  //pre: There is an existing linked list (DNA)
  //post: A linked list (DNA) is deallocated (including nucleotides) to have no memory leaks!
Sequencer::~Sequencer()
{
	//m_dna.clear();
}
  //name: readFile
  //pre: Valid file name of characters (Either A, T, G, or C)
  //post: Populates the LinkedList (DNA)
void Sequencer::readFile()
{
	string holder;;
	fstream file;
	file.open(m_fileName.c_str());
	while(getline(file,holder,'\n'))
	{ 
		m_dna.InsertEnd(holder[0]);
		//cout<<m_dna->m_tail<<endl;
	}	
}
  //name: mainMenu
  //pre: Populated LinkedList (DNA)
  //post: None
void Sequencer::mainMenu()
{
	bool flag = true;
	int choice;
	do{
		cout<<"What would you like to do?"<<endl;
		cout<<"1. Display Sequencer (Leading Strand"<<endl;
		cout<<"2. Display Sequencer (Base Pairs)"<<endl;
		cout<<"3. Inventory Basic Amino Acids"<<endl;
		cout<<"4. Sequence Entire DNA Strand"<<endl;
		cout<<"5. Exit"<<endl;
		cin>>choice;

		if(choice == 1 or choice == 2)
		{
			m_dna.Display(choice);
		}
		else if(choice == 3)
		{
			m_dna.NumAmino("Tryptophan","TGG");
			m_dna.NumAmino("Phenylalanine","TTT");
		}
		else if(choice == 4)
		{
			m_dna.Sequence();
		}
		else if(choice == 5)
		{
			flag  = false;
		}
		else{
			cout<<"Invalid choice"<<endl;
		}
	}while(flag);
}