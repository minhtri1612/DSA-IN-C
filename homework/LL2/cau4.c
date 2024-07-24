//  Write functions to implement basic operations of a queue: 
// 1. Create an empty queue 
// 2. isEmpy() 
// 3. Insert an element at the tail of a queue 
// 4. Delete an element at the head of a queue 

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct queue {
    struct Node* head;
    struct Node* tail;
};
typedef struct queue* Queue;

// 1. Create an empty queue 
Queue CreateQueue() {
    Queue Q = malloc(sizeof(struct queue));
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}
// 2. isEmpy() 
int isEmpy(Queue Q){
    return Q->tail=NULL;
}
// 3. Insert an element at the tail of a queue 
void Enqueue(Queue Q, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (Q->tail != NULL) {
        Q->tail->next = newNode;
    }
    Q->tail = newNode;
    if (Q->head == NULL) {
        Q->head = newNode;
    }
}

// 4. Delete an element at the head of a queue 
int Dequeue(Queue Q) {
    struct Node* temp = Q->head;
    int data = temp->data;
    Q->head = Q->head->next;
    if (Q->head == NULL) {
        Q->tail = NULL;
    }
    free(temp);
    return data;
}

// Function to print the queue
void PrintQueue(Queue Q) {
    struct Node* current = Q->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Queue Q = CreateQueue();
    Enqueue(Q, 1);
    Enqueue(Q, 2);
    Enqueue(Q, 3);
    PrintQueue(Q);

    printf("Dequeued: %d\n", Dequeue(Q));
    PrintQueue(Q);

    printf("Dequeued: %d\n", Dequeue(Q));
    PrintQueue(Q);

    Enqueue(Q, 4);
    PrintQueue(Q);
    

    return 0;
}
