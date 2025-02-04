#include<iostream>
using namespace std;

int fib(int n) {
	if (n <= 1)  
        return n;
    else
        return (fib(n - 1) + fib(n - 2));
}

int main() {
	int n;
	cout<<"Enter nth term of fibonacci series: ";
	cin>>n;
	cout<<"Fibonacci series up to "<<n<<"th term is "<<endl;
	for (int i=0;i<n;i++) {
        cout<<fib(i)<<"\t";  
    }
	return 0;
}