#include <stdio.h>
#include <stdlib.h>
void merge(int a[100], int left,int middle, int right){
    //ben trai: left->middle
    //ben phai:middle+1->right
    int len_left= middle-left+1;
    int len_right=right-middle;
    //tao mang tam thoi
    int a_left[len_left];
    int a_right[len_right];
    for(int i=0;i<len_left;i++){
        a_left[i]=a[left+i];
    }
    for(int i=0;i<len_right;i++){
        a_right[i]=a[middle+1+i];
    }
    //gop 2 mang theo quy tac thang nao nho hon thi them vao
    int i1=0;// vi tri hien tai cua phan tu mang ben trai
    int i2=0;// vi tri hien tai cua phan tu mang ben phai
    int k=left;
    while(i1<len_left &&i2<len_right){
        if(a_left[i1]<=a_right[i2]){
            a[k]=a_left[i1];
            i1++;
        }
        else{
            a[k]=a_right[i2];
            i2++;
        }
        k++;
    }
    while(i1<len_left){
        a[k]=a_left[i1];
        i1++;
        k++;
    }
    while(i2<len_right){
        a[k]=a_right[i2];
        i2++;
        k++;
    }

}
void mergeSort(int a[100], int left, int right){
    if(left<right){
        int middle=(left+right)/2;
        mergeSort(a,left,middle);
        mergeSort(a,middle+1,right);
        merge(a,left,middle,right);
    }
}

void Print(int a[100], int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n;
    printf("nhap so luong phan tu:");
    scanf("%d",&n);
    int a[100];
    printf("iist khi dau:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    mergeSort(a,0,n-1);
    Print(a,n);
    
}