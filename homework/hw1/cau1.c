// Write a function which swaps two integer using pointer in C language: 
// Swap(int* x, int* y). Write a simple program to test this function
#include <stdio.h>
void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void swapArray(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}

void printArr(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);    
    }
}
int main(){
    int a[]={3,5,1,6,8};
    int n=sizeof(a)/sizeof(a[0]);
    printArr(a,n);
    printf("\n");
    swapArray(a,n);
    printArr(a,n);

}
