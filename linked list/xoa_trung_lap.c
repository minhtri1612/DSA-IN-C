#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

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

// void loaitrunglap(struct node** head){
//     struct node* current = *head;
//     while(current != NULL && current->next != NULL) {
//         if(current->data == current->next->data) {
//             struct node* nextnode = current->next;
//             current->next = nextnode->next;
//             free(nextnode);
//         } else {
//             current = current->next;
//         }
//     }
// }


void loaitrunglap(struct node** head){
    struct node* temp = *head;
    while(temp != NULL && temp->next != NULL) {
        if(temp->data == temp->next->data) {
            struct node* nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
        } else {
            temp = temp->next;
        }
    }
}

int main(){
    struct node* head = NULL; 

    insertnode(&head, createnode(1));
    insertnode(&head, createnode(2));
    insertnode(&head, createnode(2));
    insertnode(&head, createnode(2));
    insertnode(&head, createnode(3));
    insertnode(&head, createnode(4));
    insertnode(&head, createnode(4));
    insertnode(&head, createnode(5));
    //loaitrunglap(&head);
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    loaitrunglap(&head);
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}