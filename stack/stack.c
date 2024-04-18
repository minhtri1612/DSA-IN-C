#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode; 
}

void display() {
    if (top == NULL) {
        return;
    }
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void peek() {
    if (top == NULL) {
        return;
    }
    printf("Top element is: %d\n", top->data);
}

void pop() {
    if (top == NULL) {
        return;
    }
    
    struct Node *temp = top;
    printf("%d\n", top->data);
    top = top->next;
    free(temp);
}

int main() {
    push(10);
    push(20);
    push(30);
    display();  
    peek();     
    pop();      
    display();  
}
