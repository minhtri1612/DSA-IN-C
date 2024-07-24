#include <stdio.h>
#include <stdlib.h>
struct HeapStruct {
    int capacity;
    int size;
    int *elements;
};
typedef struct HeapStruct *PriorityQueue;
PriorityQueue initialize(int max) {
    PriorityQueue H = malloc(sizeof(struct HeapStruct));
    H->elements = malloc((max + 1) * sizeof(int));
    H->capacity = max;
    H->size = 0;
    H->elements[0] = -1;  
    return H;
}
int deleteMin(PriorityQueue H) {
    if (H->size == 0) {
        perror("Heap is empty");
        return H->elements[0];  
    }
    int minElement = H->elements[1];
    int lastElement = H->elements[H->size--];
    int i, child;

    for (i = 1; i * 2 <= H->size; i = child) {
        child = i * 2;
        if (child != H->size && H->elements[child + 1] < H->elements[child]) {
            child++;
        }
        if (lastElement > H->elements[child]) {
            H->elements[i] = H->elements[child];
        } else {
            break;
        }
    }
    H->elements[i] = lastElement;
    return minElement;
}
void insert(int x, PriorityQueue H) {
    if (H->size == H->capacity) {
        perror("Heap is full");
        return;
    }
    int i;
    for (i = ++H->size; H->elements[i / 2] > x; i /= 2) {
        H->elements[i] = H->elements[i / 2];
    }
    H->elements[i] = x;
}
void printHeap(PriorityQueue H) {
    for (int i = 1; i <= H->size; i++) {
        printf("%d ", H->elements[i]);
    }
    printf("\n");
}
int main() {
    int maxCapacity = 10;
    PriorityQueue H = initialize(maxCapacity);
    insert(13, H);
    insert(21, H);
    insert(16, H);
    insert(24, H);
    insert(31, H);
    insert(19, H);
    insert(68, H);
    insert(65, H);
    insert(26, H);
    insert(32, H);

    printf("Min Heap: ");
    printHeap(H);

    printf("Deleted min element: %d\n", deleteMin(H));
    printf("Min Heap after deletion: ");
    printHeap(H);

    // Clean up
    free(H->elements);
    free(H);

    return 0;
}
