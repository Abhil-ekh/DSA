#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)  
        return a;
    else
        return gcd(b, a % b);  
}

int main() {
    int a, b;
    cout << "Enter two numbers to find their GCD: ";
    cin >> a >> b;
    cout << "GCD of two numbers is " << gcd(a, b) << endl;
    return 0;
}
