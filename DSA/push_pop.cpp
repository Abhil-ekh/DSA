#include<iostream>
using namespace std;
class Stack{
	private:
		int top,item;
		int a[10];
	public:
		Stack(){
			top=-1;
		}
		void push(){
			if(top==10-1)
				cout<<endl<<"Stack Overflow";
			else{
				cout<<endl<<"Enter item to be pushed: ";
				cin>>item;
				a[++top]=item;	
			}
			
		}
		void pop(){
			if(top==-1)
				cout<<endl<<"Stack Underflow";
			else
				cout<<a[top--]<<" popped"<<endl;
		}
		void tops(){
			cout<<"Item at top of the stack is: "<<a[top]<<endl;
		}
};
int main(){
	int ch;
	char c;
	Stack s;
	do{
		cout<<"Stack Operation: \n1. Push \n2. Pop \n3. View top of the stack \nEnter your choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				s.push();
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.tops();
				break;
			default:
					cout<<"Invalid input"<<endl;
		}
		cout<<endl<<"Continue? (Y/N): ";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;	
}