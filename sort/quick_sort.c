#include <stdio.h>
void swap(int*a, int*b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int Partition(int arr[], int lb, int Ub){
    int Pivot=arr[lb];
    int start=lb;
    int end=Ub;
    while(start<end){
        while(arr[start]<=Pivot){
            start++;
        }
        while(arr[end]>Pivot){
            end--;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

void QuickSort(int arr[], int lb, int Ub) {
    if (lb < Ub) {
        int loc = Partition(arr, lb, Ub);
        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, Ub);
    }
}
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    int arr[] = {3, 1, 5, 7, 2, 8, 9, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printarray(arr, n);
    QuickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printarray(arr, n);
    return 0;
}