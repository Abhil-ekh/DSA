#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class List {
	private:
		Node* head;
	public:
		List() {
			head=NULL;
		}
		Node* insertNode() {
			Node *newNode=new Node();
			cout<<endl<<"Enter data to be inserted at front : ";
			cin>>newNode->data;
			return(newNode);
		}
		void insertAtFront() {
			Node *newNode=insertNode();
			newNode->next=head;
			head=newNode;
		}
		void insertAtMid() {
			Node *newNode=insertNode();
			
		}
		void insertAtEnd() {
    		Node* newNode = insertNode();  
    		newNode->next = NULL;
    		if (head == NULL) 
        		head = newNode;
    
    		else {
        		Node* temp = head;
        		while (temp->next != NULL)
            		temp = temp->next;
        	temp->next = newNode;
    		}
		}
		void traverse(){
			struct Node* temp=head;
			if(temp==NULL)
				cout<<endl<<"List is empty"<<endl;
			else
			{
				cout<<endl<<"Linked List :"<<endl;
				while(temp!=NULL)
				{
					cout<<temp->data<<"\t";
					temp=temp->next;
				}	
			}
			cout<<endl;
		}
};
int main() {
	List l;
	int ch;
	char choice;
	do {
		cout<<"Linked List Insertion Operations :\n1. At the beginning\n2. At the middle\n3. At the end\n4. Traverse\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				l.insertAtFront();
				break;
			//case 2:
			//	l.insertAtMiddle();
			//	break;
			case 3:
				l.insertAtEnd();
				break;
			case 4:
				l.traverse();
				break;
			default:
				cout<<endl<<"Invalid input"<<endl;
		}
		cout<<endl<<"Again? (Y/N) : ";
		cin>>choice;
	}while(choice=='y' || choice=='Y');
	return 0;
}