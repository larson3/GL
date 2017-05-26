#include <iostream>
#include <string>
using namespace std;

const int START = 0;
const int END = 10;

struct Node {
  int num;
  Node * next;
};

class LinkedList{
public:
  LinkedList(){m_head = NULL;}
  ~LinkedList(){
    Node * ptrNode = m_head;    
    while(ptrNode != NULL){
      ptrNode = m_head->next;
      delete m_head;
      m_head = ptrNode;
    }
  }
  void insert(int value, bool location){
    //If the linked list is empty
    if (m_head == NULL){
      //Step 1: Code when linked list is empty
		Node *newNode = new Node();
		m_head = newNode;
		m_head->next = NULL;
		m_head->num = value;
    }

    //If we are inserting in the beginning of the linked list
    else if(location == false){
      //Step 2: Code when you are doing an insert beginning
		Node *newNode = new Node();
		newNode->next = m_head;
		m_head = newNode;
		newNode->num = value;

    }
    //If we are inserting in the end of the linked list
    //**RECURSIVE**
    //Calls insertHelper
    else if(location == true){
      //Step 3: Code when you are doing an insert end (recursively)
		Node *curNode = m_head;
		insertHelper(curNode,value);
    }
  }
  void insertHelper(Node *curNode, int value){
    //Step 4: Code the recursive function for insert end
	if(curNode->next == NULL)
	{
		Node *newNode = new Node;
		curNode->next = newNode;
		newNode->next = NULL;
		newNode->num = value;
		return;
	}
	else{
		insertHelper(curNode->next,value);
	}
	return;
 }

  //Iterates through linked list and displays
  void display(){
    Node * ptrNode = m_head;
    while(ptrNode){
      cout << ptrNode->num << "-->";
      ptrNode = ptrNode->next;
    }
    cout << "END" << endl;
  }

private:
  Node* m_head;
};

//Creates linked list and inserts 0-9 then displays
int main (){
  LinkedList ll;
  for(int i = START; i < END;i++){
    ll.insert(i, 1);
  }
  ll.display();
  return 0;
}
