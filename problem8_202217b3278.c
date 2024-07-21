#include <stdio.h>
 
// Function to find the position of the smallest element in the array from index i to n
int smallest(int arr[], int i, int n) {
    int small = arr[i];
    int pos = i;
    for (int j = i + 1; j < n; j++) {
        if (small > arr[j]) {
            small = arr[j];
            pos = j;
        }
    }
    return pos;
}
 
// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int pos, temp;
    for (int i = 0; i < n - 1; i++) {
        // Find the position of the smallest element in the unsorted part
        pos = smallest(arr, i, n);
        // Swap the current element with the smallest element found
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}
 
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 
// Main function
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Unsorted array: \n");
    printArray(arr, n);
 
    selectionSort(arr, n);
 
    printf("Sorted array: \n");
    printArray(arr, n);
 
    return 0;
}
 