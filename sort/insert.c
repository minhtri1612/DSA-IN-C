#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertnode(struct node** head, struct node* newnode) {
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertnodeAtTheBeginning(struct node** head, struct node* newnode){
     if (*head == NULL) {
        *head = newnode;
    } 
    else{
        newnode->next=*head;
        *head=newnode;
    }
}

void insertPOSITION(struct node** head, struct node* newnode){
    int pos;
    printf("nhap vi tri muon insert:");
    scanf("%d",&pos);
    struct node* temp = *head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
int main() {
    struct node* head = NULL; // Initialize head to NULL

    insertnode(&head, createnode(2));
    insertnode(&head, createnode(3));
    insertnode(&head, createnode(145));
    insertnode(&head, createnode(67));
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
   struct node* newNode = createnode(100);
    insertPOSITION(&head, newNode);

    // Print the linked list again to verify insertion at the specified position
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
