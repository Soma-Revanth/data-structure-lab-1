#include <stdio.h>
 
void merge(int arr[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;
 
    // Create temporary arrays
    int Left[n1], Right[n2];
 
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        Left[i] = arr[beg + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];
 
    // Merge the temporary arrays back into arr[beg..end]
    int i = 0, j = 0, k = beg;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of Left[], if there are any
    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of Right[], if there are any
    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = beg + (end - beg) / 2;
 
        // Sort first and second halves
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
 
        merge(arr, beg, mid, end);
    }
}
 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}