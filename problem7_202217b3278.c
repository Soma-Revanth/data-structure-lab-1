#include <stdio.h>
 
// Function to perform Bubble Sort
void bubbleSort(int array[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        // Flag to check if any swap happened
        int swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped, the array is already sorted
        if (!swapped)
            break;
    }
}
 
// Function to print the array
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
 
// Main function
int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);
 
    printf("Unsorted array: \n");
    printArray(array, size);
 
    bubbleSort(array, size);
 
    printf("Sorted array: \n");
    printArray(array, size);
 
    return 0;
}