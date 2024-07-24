#include <stdio.h>
void insertSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    insertSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}