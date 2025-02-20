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
			cout<<"Enter data to be inserted: ";
			cin>>newNode->data;
			return(newNode);
		}
		void insertAtFront() {
			Node *newNode=insertNode();
			newNode->next=head;
			head=newNode;
		}
		void insertAtMiddle() {
			Node *newNode=insertNode();
            if (head == NULL) {
                newNode->next = NULL;
                head = newNode;
                return;
            }
            int pos;
            cout << "Enter position to insert at (1 for first node): ";
            cin >> pos;
            Node* temp = head;
            int count = 1;
            while (temp != NULL && count < pos - 1) {
                temp = temp->next;
                count++;
            }
            if (temp == NULL) {
                cout << "Position exceeds the length of the list. Inserting at the end instead." << endl;
                newNode->next = NULL;
                while (temp != NULL && temp->next != NULL) 
                    temp = temp->next;
                if (temp != NULL) 
                    temp->next = newNode;
                else
                head = newNode;    
			}
            else {
                	newNode->next = temp->next;
                	temp->next = newNode;
           		}
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
		cout<<endl<<"Linked List Insertion Operations :\n1. At the beginning\n2. At the middle\n3. At the end\n4. Traverse\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				l.insertAtFront();
				break;
			case 2:
				l.insertAtMiddle();
				break;
			case 3:
				l.insertAtEnd();
				break;
			case 4:
				l.traverse();
				break;
			default:
				cout<<endl<<"Invalid input"<<endl;
		}
		cout<<"Again? (Y/N) : ";
		cin>>choice;
	}while(choice=='y' || choice=='Y');
	return 0;
}