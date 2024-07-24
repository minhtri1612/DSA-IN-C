#include <stdio.h>

void InsertionSort(int A[], int N) {
    for (int i = 1; i < N; i++) {
        int Temp = A[i];
        int j;
        for (j = i; j > 0 && A[j-1] > Temp; j--) {
            A[j] = A[j-1];
        }
        A[j] = Temp;
    }
}

// Helper function to print the array
void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {5, 2, 9, 1, 5, 6};
    int N = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, N);

    InsertionSort(A, N);

    printf("Sorted array: ");
    printArray(A, N);

    return 0;
}
