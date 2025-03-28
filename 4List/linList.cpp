#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {
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
		void deleteFromFront() {
			if (head == NULL) {
        		cout << "Void deletion: List is empty" << endl;
        		return;
   	 		}
			Node* temp=head;
			head=temp->next;
			temp->next=NULL;
			free(temp);
		}
		void deleteSpecific() {
			if (head == NULL) {
        		cout << "List is empty!" << endl;
        		return;
    		}
			int n;
    		cout << "Enter the node to delete (1 for the first node): ";
    		cin >> n;
    		Node* temp1 = head;
    		if (n == 1) {
       			head = head->next; 
        		temp1->next = NULL;
        		delete temp1; 
        		return;
    		}
    		Node* temp2 = NULL;
			for (int i = 1; temp1 != NULL && i < n; i++) {
 		    	temp2 = temp1;
        		temp1 = temp1->next;
    		}
    		if (temp1 == NULL) {
        		cout << "Invalid position!" << endl;
        		return;
    		}
    		temp2->next = temp1->next;
    		temp1->next = NULL;
    		delete temp1; 
    		cout << "Node " << n << " deleted successfully." << endl;
		}
		void deleteFromEnd() {
			if (head == NULL) {
				Node* temp=head;
				head=NULL;
				free(temp);
			}
    		else {
        		Node* temp1=head;
                Node* temp2;
				while(temp1->next!=NULL){
					temp2=temp1;
					temp1=temp1->next;
				}
				temp2->next=NULL;
				free(temp1);
    		}
		}
		void search() {
			if (head == NULL) {
				cout << "List is empty!" << endl;
				return;
			}
			int key;
			cout << "Enter the value to search: ";
			cin >> key;
			Node* current = head; 
			int position = 1; 
			while (current != NULL) { 
				if (current->data == key) { 
					cout << "Value " << key << " found at position " << position << "." << endl;
					return;
				}
				current = current->next; 
				position++;
			}
			cout << "Value " << key << " not found in the list." << endl;
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
	LinkedList l;
	int ch;
	char choice;
	do {
		cout<<endl<<"Singly Linked List Operations :\n1. Insersion At the beginning\n2. Insersion At the middle\n3. Insersion At the end\n4. Deletion From the beginning \n5. Deletion From the middle \n6. Deletion From the end \n7. Traverse\nEnter your choice : ";
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
				l.deleteFromFront();
				break;
			case 5:
				l.deleteSpecific();
				break;
			case 6:
				l.deleteFromEnd();
				break;
			case 7:
				l.search();
				break;
			case 8:
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