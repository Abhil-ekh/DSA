#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {7,6,11,3,21,1,9};
    int n = sizeof(arr) / 4;
    cout << "Original array: ";
    printArray(arr, n);
    selectionSort(arr, n); 
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
