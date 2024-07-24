// a. Write a program to allow user input size of a 2D-array and enter the value 
// for each elements of this 2D-array. 
// b. Print the sum of this 2D-array by using pointer 
// c. If we consider 2D-array as a matrix, please print the transpose of this 
// matrix 
#include <stdio.h>
#include <stdlib.h>
void printArray(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int sumArray(int** arr, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += *(*(arr + i) + j); 
        }
    }
    return sum;
}

void printTranspose(int** arr, int n, int m) {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Nhap so dong: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Nhap cac gia tri cua mang 2 chieu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Mang 2 chieu vua nhap:\n");
    printArray(arr, n, m);

    int sum = sumArray(arr, n, m);
    printf("Tong cac phan tu cua mang 2 chieu: %d\n", sum);

    printf("Ma tran chuyen vi:\n");
    printTranspose(arr, n, m);

    

    return 0;
}
