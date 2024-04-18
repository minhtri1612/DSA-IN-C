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
void insertnode(struct node**head, struct node* newnode){
    if (*head == NULL) {
        *head = newnode;
    } 
    else{
        newnode->next=*head;
        *head=newnode;
    }
}
void deleteATTHEBEGINNING(struct node**head){
    struct node*temp=*head;
    *head=(*head)->next;
    free(temp);

}

int main(){
    struct node* head = NULL;

    insertnode(&head, createnode(1));
    insertnode(&head, createnode(2));
    insertnode(&head, createnode(3));
    insertnode(&head, createnode(4));
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    deleteATTHEBEGINNING(&head);
    printf("\n");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}