#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to insert an element into the heap
void insertHeap(int arr[], int *n, int data) {
    // Increment the size of the heap
    *n = *n + 1;
    int i = *n;
    arr[i] = data;

    // Fix the max heap property if it is violated
    while (i > 1 && arr[i / 2] < arr[i]) {
        swap(&arr[i / 2], &arr[i]);
        i = i / 2;
    }
}

// Function to maintain the max heap property
void Maxheapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r <= n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        Maxheapify(arr, n, largest);
    }
}

// Function to print the heap
void printHeap(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; // Assuming a maximum size of 100 for the heap
    int n = 0;    // Initial size of the heap

    // Inserting elements into the heap
    insertHeap(arr, &n, 10);
    insertHeap(arr, &n, 20);
    insertHeap(arr, &n, 15);
    insertHeap(arr, &n, 30);
    insertHeap(arr, &n, 40);

    // Printing the heap
    printf("Max Heap: ");
    printHeap(arr, n);

    // Manually violating heap property to demonstrate Maxheapify
    arr[1] = 5;
    printf("After violating heap property: ");
    printHeap(arr, n);

    // Fixing the heap property
    Maxheapify(arr, n, 1);
    printf("After fixing heap property: ");
    printHeap(arr, n);

    return 0;
}