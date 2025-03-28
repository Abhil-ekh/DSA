#include<iostream>
#define MAX 5
using namespace std;

class priorQueue {
    private:
        int a[MAX], priority[MAX], rear, front, item, itemPriority;
        int i;
    public:
        priorQueue() {
            rear = front = -1;
        }

        void enQueue() {
            if (rear == MAX - 1) {
                cout << "Queue Overflow";
                return;
            }
            cout  << "Enter item to be put on queue: ";
            cin >> item;
            cout << "Enter priority of the item (lower number = higher priority): ";
            cin >> itemPriority;
            if (front == -1) 
                front = 0;
            rear++;
            a[rear] = item;
            priority[rear] = itemPriority;
            for (i = front; i <= rear; i++) {
                for (int j = i + 1; j <= rear; j++) {
                    if (priority[i] > priority[j]) {
                        int tempPriority = priority[i];
                        priority[i] = priority[j];
                        priority[j] = tempPriority;
                        int tempItem = a[i];
                        a[i] = a[j];
                        a[j] = tempItem;
                    }
                }
            }
        }

        void deQueue() {
            if (front == -1 || front > rear) {
                cout << "Queue is empty";
                return;
            }
            cout << a[front] << " with priority " << priority[front] << " dequeued";
            front++;
            if (front > rear) {
                front = rear = -1;
            }
        }
};

int main() {
    int ch;
    char c;
    priorQueue pq;
    do {
        cout << "Priority Queue Operations: \n1. Enqueue \n2. Dequeue \nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                pq.enQueue();
                break;
            case 2:
                pq.deQueue();
                break;
            default:
                cout << "Invalid input" << endl;
        }
        cout  << "Continue? (Y/N): ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return 0;
}
