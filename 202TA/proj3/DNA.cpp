#include "DNA.h"

DNA::DNA()
{
	m_head = NULL;
	m_tail = NULL;
	m_size = 0;
}

DNA::~DNA()
{
	Clear();
}
  
void DNA::InsertEnd(char payload)
{
	Nucleotide *temp = new Nucleotide;
	temp->m_payload = payload;
	if(m_head == NULL and m_tail ==NULL)
	{
		m_head = temp;
		m_tail = temp;
	}
	else{
		temp->m_next = NULL;
		m_tail->m_next = temp;
		m_tail = temp;
	}
	m_size++;
}
  
void DNA::Display(int numStrand)
{
	int count = 0;
	string pair;
	cout<<"Base Pairs"<<endl;
	if(numStrand == 1)
	{
		Nucleotide *ptr = m_head;
		while(ptr!=NULL)
		{
			cout<<ptr->m_payload<<endl;
			ptr = ptr->m_next;
			count++;
		}
	}
	else
	{
		Nucleotide *ptr = m_head;
		while(ptr!=NULL)
		{
			if(ptr->m_payload == 'A')
			{
				pair = "T";
			}
			else if(ptr->m_payload == 'T')
			{
				pair = "A";
			}
			else if(ptr->m_payload == 'G')
			{
				pair = "C";
			}
			else if(ptr->m_payload == 'C')
			{
				pair = "G";
			}
			cout<<ptr->m_payload<<"-"<<pair<<endl;
			ptr = ptr->m_next;
			count++;
		}
	}
	cout<<"END"<<endl;
	cout<<count<<" base pairs listed."<<endl;
	cout<<count/3<<" trinucleotides listed."<<endl;
}
  
void DNA::NumAmino(string name, string trinucleotide)
{
	int count = 0;
	int foundTotal = 0;
	string holder = "";
	Nucleotide *ptr = m_head;
	while(ptr!=NULL)
	{
		//cout<<ptr->m_payload<<endl;
		holder += ptr->m_payload;
		ptr = ptr->m_next;
		count++;
		if(count % 3 == 0)
		{
			if(name.compare(Translate(holder)) == 0)
			{
				foundTotal++;
			}
		holder = "";
		}
	}
	cout<<name<<": "<<foundTotal<<" identified"<<endl;
}
  
void DNA::Sequence()
{
	int count = 0;
	string holder = "";
	Nucleotide *ptr = m_head;
	cout<<"Amino Acid List"<<endl;
	while(ptr!=NULL)
	{
		holder += ptr->m_payload;
		ptr = ptr->m_next;
		count++;
		if(count % 3 == 0)
		{
			cout<<Translate(holder)<<endl;
			holder = "";
		}
	}
}
  
string DNA::Translate(string trinucleotide)
{
  if((trinucleotide=="ATT")||(trinucleotide=="ATC")||(trinucleotide=="ATA"))
    return ("Isoleucine");
  else if((trinucleotide=="CTT")||(trinucleotide=="CTC")||(trinucleotide=="CTA")||
	  (trinucleotide=="CTG")|| (trinucleotide=="TTA")||(trinucleotide=="TTG"))
    return ("Leucine");
  else if((trinucleotide=="GTT")||(trinucleotide=="GTC")||
	  (trinucleotide=="GTA")||(trinucleotide=="GTG"))
    return ("Valine");
  else if((trinucleotide=="TTT")||(trinucleotide=="TTC"))
    return ("Phenylalanine");
  else if((trinucleotide=="ATG"))
    return ("Methionine");
  else if((trinucleotide=="TGT")||(trinucleotide=="TGC"))
    return ("Cysteine");
  else if((trinucleotide=="GCT")||(trinucleotide=="GCC")||
	  (trinucleotide=="GCA")||(trinucleotide=="GCG"))
    return ("Alanine");
  else if((trinucleotide=="GGT")||(trinucleotide=="GGC")||
	  (trinucleotide=="GGA")||(trinucleotide=="GGG"))
    return ("Glycine");
  else if((trinucleotide=="CCT")||(trinucleotide=="CCC")||
	  (trinucleotide=="CCA")||(trinucleotide=="CCG"))
    return ("Proline");
  else if((trinucleotide=="ACT")||(trinucleotide=="ACC")||
	  (trinucleotide=="ACA")||(trinucleotide=="ACG"))
    return ("Threonine");
  else if((trinucleotide=="TCT")||(trinucleotide=="TCC")||
	  (trinucleotide=="TCA")||(trinucleotide=="TCG")||
	  (trinucleotide=="AGT")||(trinucleotide=="AGC"))
    return ("Serine");
  else if((trinucleotide=="TAT")||(trinucleotide=="TAC"))
    return ("Tyrosine");
  else if((trinucleotide=="TGG"))
    return ("Tryptophan");
  else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
    return ("Glutamine");
  else if((trinucleotide=="AAT")||(trinucleotide=="AAC"))
    return ("Asparagine");
  else if((trinucleotide=="CAT")||(trinucleotide=="CAC"))
    return ("Histidine");
  else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
    return ("Glutamic acid");
  else if((trinucleotide=="GAT")||(trinucleotide=="GAC"))
    return ("Aspartic acid");
  else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
    return ("Lysine");
  else if((trinucleotide=="CGT")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
	  (trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
    return ("Arginine");
  else if((trinucleotide=="TAA")||(trinucleotide=="TAG")||(trinucleotide=="TGA"))
    return ("Stop");
  else
    cout << "returning unknown" << endl;
  return ("Unknown");
}

  
bool DNA::IsEmpty()
{
	return true;
}
  
void DNA::SizeOf()
{
	
}

void DNA::Clear()
{
		Nucleotide *ptr = m_head;
		Nucleotide *old = NULL;
		while(ptr!=NULL)
		{
			old = ptr;
			ptr = ptr->m_next;
			delete old;
		}
}