#include<iostream>
#define MAX 5
using namespace std;

class CirQueue{
	private:
		int a[MAX],rear,front,item;
		int i;
	public:
		CirQueue(){
			rear=front=-1;
		}	
		void enQueue(){
			if((rear + 1) % MAX == front)
				cout<<"Queue Overflow";
			else{
				cout<<endl<<"Enter item to be put on queue: ";
				cin>>item;
				if (front == -1)
                	front = 0;
            	rear = (rear + 1) % MAX;
           	 	a[rear] = item;
			}
		}
		void deQueue() {
        	if (front == -1)
            	cout << "Queue is empty" << endl;
			else {
            	cout << a[front] << " Dequeued" << endl;
            	if (front == rear) 
                		front = rear = -1;
                else 
                front = (front + 1) % MAX;
        	}
    	}	
		void traverse(){
			if(front==-1 && rear==-1)
				cout<<"Stack is empty";
			else {
            	int i = front;
            	while (i != rear) {
					cout << a[i] << "\t";
                	i = (i + 1) % MAX;
            	}
            cout << a[rear] << endl; 
        	}			
		}	
};

int main(){
	int ch;
	char c;
	CirQueue q;
	do{
		cout<<"Queue Operation: \n1. Enqueue \n2. Dequeue \n3. Traverse \nEnter your choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				q.enQueue();
				break;
			case 2:
				q.deQueue();
				break;
			case 3:
				q.traverse();
				break;
			default:
					cout<<"Invalid input"<<endl;
		}
		cout<<endl<<"Continue? (Y/N): ";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;	
}