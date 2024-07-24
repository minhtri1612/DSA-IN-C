#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int tinhtong(struct Node* head){
    int sum=0;
    struct Node* temp = head;
    while(temp!=NULL){
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);
    insertAtBeginning(&head, 8);

    printf("Linked List: ");
    printList(head);

    printf("\nList after sorting: ");
    //head = mergeSort(head);
    printList(head);
    int tong=tinhtong(head);
    printf("tong cua linked list la:%d",tong);
    
}
