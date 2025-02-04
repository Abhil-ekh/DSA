#include<iostream>
#define MAX 5
using namespace std;

class dobendQueue {
    private:
        int a[MAX], front, rear;
    public:
        dobendQueue() {
            front = rear = -1;
        }

        bool isFull() {
            return (front == 0 && rear == MAX - 1) || (front == rear + 1);
        }

        bool isEmpty() {
            return (front == -1);
        }

        void insertFront() {
            if (isFull()) {
                cout << "Queue Overflow!";
                return;
            }

            int item;
            cout << "Enter item to insert at front: ";
            cin >> item;

            if (isEmpty()) {  
                front = rear = 0;
            } else if (front == 0) {
                front = MAX - 1;
            } else {
                front--;
            }
            a[front] = item;
        }

        void insertRear() {
            int item;
            if (isFull()) {
                cout << "Queue Overflow!";
                return;
            }
            cout << "Enter item to insert at rear: ";
            cin >> item;

            if (isEmpty()) {  
                front = rear = 0;
            } 
            else if (rear == MAX - 1) {
                rear = 0;
            } 
            else {
                rear++;
            }
            a[rear] = item;
        }

        void deleteFront() {
            if (isEmpty()) {
                cout << "Queue Underflow!";
                return;
            }
            cout << a[front] << " deleted from front\n";
            if (front == rear) {  
                front = rear = -1;
            } 
            else if (front == MAX - 1) {
                front = 0;
            } 
            else {
                front++;
            }
        }

        void deleteRear() {
            if (isEmpty()) {
                cout << "Queue Underflow!";
                return;
            }
            cout << a[rear] << " deleted from rear\n";
            if (front == rear) {  
                front = rear = -1;
            } 
            else if (rear == 0) {
                rear = MAX - 1;
            } 
            else {
                rear--;
            }
        }

        void traverse() {
            if (isEmpty()) {
                cout << "Deque is empty!";
                return;
            }
            cout << "Deque elements: ";
            int i = front;
            while (true) {
                cout << a[i] << "\t";
                if (i == rear)
                    break;
                i = (i + 1) % MAX;
            }
            cout << endl;
        }
};

int main() {
    int ch;
    char c;
    dobendQueue deq;
    do {
        cout << "\nDouble-Ended Queue Operations:\n";
        cout << "1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Traverse\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                deq.insertFront();
                break;
            case 2:
                deq.insertRear();
                break;
            case 3:
                deq.deleteFront();
                break;
            case 4:
                deq.deleteRear();
                break;
            case 5:
                deq.traverse();
                break;
            default:
                cout << "Invalid input!\n";
        }
        cout << "Continue? (Y/N): ";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    return 0;
}
