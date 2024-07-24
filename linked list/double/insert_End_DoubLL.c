#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void insertTheEnd(struct Node **head_ref, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head_ref == NULL) {
        newNode->prev = NULL;
        *head_ref = newNode;
        return;
    }
    struct Node *temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    struct Node *head = NULL;
    insertTheEnd(&head, 10);
    insertTheEnd(&head, 20);
    insertTheEnd(&head, 30);
    insertTheEnd(&head, 40);
    printList(head);

    return 0;
}
