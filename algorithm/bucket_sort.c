#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bucket sort function
void bucketSort(int arr[], int n) {
    int i, j, k, max_val = arr[0], min_val = arr[0];
    
    // Find the maximum and minimum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
        if (arr[i] < min_val) min_val = arr[i];
    }

    // Number of buckets
    int bucket_count = max_val - min_val + 1;
    int **buckets = (int **)malloc(bucket_count * sizeof(int *));
    int *bucket_sizes = (int *)calloc(bucket_count, sizeof(int));

    // Allocate memory for each bucket
    for (i = 0; i < bucket_count; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute the array elements into different buckets
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] - min_val;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    // Sort individual buckets and concatenate the result
    k = 0;
    for (i = 0; i < bucket_count; i++) {
        insertionSort(buckets[i], bucket_sizes[i]);
        for (j = 0; j < bucket_sizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]); // Free memory allocated for bucket
    }

    free(buckets); // Free memory allocated for buckets array
    free(bucket_sizes); // Free memory allocated for bucket sizes array
}

int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
