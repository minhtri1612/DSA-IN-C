#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int n, int arr2[], int m, int merged[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge the arrays
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n) {
        merged[k++] = arr1[i++];
    }
    while (j < m) {
        merged[k++] = arr2[j++];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

double findMedian(int merged[], int size) {
    if (size % 2 == 0) {
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    } else {
        return merged[size / 2];
    }
}

int main() {
    int arr1[] = {3, 6, 1, 2, 4};
    int arr2[] = {2, 6, 77, 8, 12};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int merged[n + m];
    
    // Sort the individual arrays first
    insertionSort(arr1, n);
    insertionSort(arr2, m);
    
    // Merge the two sorted arrays
    merge(arr1, n, arr2, m, merged);
    
    // Print the merged sorted array
    printf("Merged and sorted array: ");
    printArray(merged, n + m);

    double median = findMedian(merged, n + m);
    printf("Median of the merged array: %.2f\n", median);
    
    return 0;
}
