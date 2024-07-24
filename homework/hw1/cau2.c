// a. Write a program to allow user input size of a 1D-array and enter the value 
// for each elements of this array. 
// b. Print the sum of this array by using pointer. 
// c. Sort this array in ascending order by using the function of Assignment 1. 
// d. Print the max value of sum of a subarray of this array by using pointer. 
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int arraySum(int *arr, int size) {
    int sum = 0;
    for (int *ptr = arr; ptr < arr + size; ptr++) {
        sum += *ptr;
    }
    return sum;
}

int maxSubArraySum(int *arr, int size) {
    int max_so_far = arr[0];
    int current_max = arr[0];

    for (int i = 1; i < size; i++) {
        current_max = (arr[i] > current_max + arr[i]) ? arr[i] : current_max + arr[i];
        max_so_far = (max_so_far > current_max) ? max_so_far : current_max;
    }
    return max_so_far;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = arraySum(arr, n);
    printf("Sum of the array: %d\n", sum);
    printf("Sorted array: ");
    printArray(arr, n);
    int max_sum = maxSubArraySum(arr, n);
    printf("Maximum sum of a subarray: %d\n", max_sum);

    free(arr);
    return 0;
}
