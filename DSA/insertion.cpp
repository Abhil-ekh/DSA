#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int k = arr[i]; 
        int j = i - 1;
        while (j>=0 && arr[j]>k) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k; 
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {7,6,11,3,21,1,9};
    int n = sizeof(arr) / 4;
    cout << "Original array: ";
    printArray(arr, n);
    insertionSort(arr, n); 
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}