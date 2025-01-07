#include<iostream>
#include <string>
#define MAX 100
using namespace std;

char stack[MAX];
int top = -1;

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int isOperand(char c) {
    return (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

void infixToPostfix(char* infix, char* postfix) {
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isOperand(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; 
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';  
}

void infixToPrefix(char* infix, char* prefix) {
    strrev(infix);
	 for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    strrev(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];
    cout<<"Enter infix expression: ";
    cin>>infix;
    infix[strcspn(infix, "\n")] = '\0';
    infixToPrefix(infix, prefix);
    cout<<"Prefix expression: "<< prefix;

    return 0;
}