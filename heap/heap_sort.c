#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertHeap(int arr[], int *n, int data) {
    (*n) = (*n) + 1;
    arr[*n] = data;
    int i = *n;
    while (i > 1) {
        int parent = i / 2;
        if (arr[parent] < arr[i]) {
            swap(&arr[parent], &arr[i]);
            i = parent;
        } else {
            return;
        }
    }
}
void Maxheapify(int arr[], int n, int i) {
    int largest = i;
    int l = i * 2;
    int r = (i * 2) + 1;

    if (l <= n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r <= n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        Maxheapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        Maxheapify(arr, n, i);
    }
    for (int i = n; i >= 2; i--) {
        swap(&arr[1], &arr[i]);
        Maxheapify(arr, i - 1, 1);
    }
}
int main() {
    int arr[100];
    int n = 0;
    insertHeap(arr, &n, 23);
    insertHeap(arr, &n, 22);
    insertHeap(arr, &n, 25);
    insertHeap(arr, &n, 11);
    insertHeap(arr, &n, 94);
    insertHeap(arr, &n, 34);
    insertHeap(arr, &n, 0);
    insertHeap(arr, &n, 6);
    insertHeap(arr, &n, 33);
    printf("Heap array before sorting: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heapsort(arr, n);
    printf("Sorted array: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
