#include <stdio.h>
#include <stdlib.h>
void insert_sort(int arr[], int lenght){
    for(int i=1;i<lenght;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={4,1,2,5,3,7,6,8,9};
    for(int i=0;i<9;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("sau khi tha doi:");
    insert_sort(arr,9);
    for(int i=0;i<9;i++){
        printf("%d ",arr[i]);
    }
}