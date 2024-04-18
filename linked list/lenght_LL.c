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

int countlenght(struct node**head){
    struct node*tmp=*head;
    int sum=0;
    while(tmp!=NULL){
        sum+=1;
        tmp=tmp->next;
    }
    return sum;
}
int main(){
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
    int tong=countlenght(&head);
    printf("do dai cua linked list la:%d",tong);
}