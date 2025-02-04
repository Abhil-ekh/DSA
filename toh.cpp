#include<iostream>
using namespace std;

int hanoi(int n,int s,int i,int d) {
    if (n==1)
        cout<<"Move disk from "<<s<<" to "<<d<<endl;
    else {
        hanoi(n-1,s,d,i);
        cout<<"Move disk from "<<s<<" to "<<d<<endl;
        hanoi(n-1,i,s,d);
    }
}

int main() {
    int n, s, d;
    cout<<"Enter no of disks: ";
    cin>>n;
    cout << "The steps to solve by Tower of Hanoi are:"<<endl<<hanoi(n,1,2,3);
    return 0;
}