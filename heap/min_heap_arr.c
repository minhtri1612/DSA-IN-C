#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to insert an element into the heap
int insertHeap(int arr[], int n, int data) {
    // Increment the size of the heap
    n = n + 1;
    int i = n;
    arr[i] = data;

    // Fix the min heap property if it is violated
    while (i > 1 && arr[i / 2] > arr[i]) {
        swap(&arr[i / 2], &arr[i]);
        i = i / 2;
    }
    
    return n; // Return the updated size of the heap
}

// Function to maintain the min heap property
void Minheapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && arr[l] < arr[smallest]) {
        smallest = l;
    }

    if (r <= n && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        Minheapify(arr, n, smallest);
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
    n = insertHeap(arr, n, 10);
    n = insertHeap(arr, n, 20);
    n = insertHeap(arr, n, 15);
    n = insertHeap(arr, n, 30);
    n = insertHeap(arr, n, 40);

    // Printing the heap
    printf("Min Heap: ");
    printHeap(arr, n);

    // Manually violating heap property to demonstrate Minheapify
    arr[1] = 50;
    printf("After violating heap property: ");
    printHeap(arr, n);

    // Fixing the heap property
    Minheapify(arr, n, 1);
    printf("After fixing heap property: ");
    printHeap(arr, n);

    return 0;
}
