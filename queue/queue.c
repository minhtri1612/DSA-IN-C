#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Definition of the Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue (remove) an element from the queue
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Function to get the front element of the queue
void peek(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front: %d\n", queue->front->data);
    }
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    peek(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    peek(queue);

    // Free the remaining elements and the queue
    while (queue->front != NULL) {
        dequeue(queue);
    }
    free(queue);

    return 0;
}
