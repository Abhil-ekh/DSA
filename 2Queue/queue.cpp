#include<iostream>
#define MAX 5
using namespace std;

class Queue{
	private:
		int a[MAX],rear,front,item;
		int i;
	public:
		Queue(){
			rear=front=-1;
		}	
		void enQueue(){
			if(rear==MAX-1)
				cout<<"Queue Overflow";
			else{
				cout<<endl<<"Enter item to be put on queue: ";
				cin>>item;
				if (front == -1) 
                    front = 0;
                rear++;
                a[rear] = item;
			}
		}
		void deQueue(){
			if(rear==-1)
				cout<<"Queue is empty";
			else{
				cout<<a[front]<<" Dequeued";
				if(rear==front)
					front=rear=-1;
				else
					front++;	
			}
		}	
		void traverse(){
			if(front==-1 && rear==-1)
				cout<<"Queue is empty";
			else
				for(i=front;i<=rear;i++ )
					cout<<a[i]<<"\t";	
		}	
};

int main(){
	int ch;
	char c;
	Queue q;
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
