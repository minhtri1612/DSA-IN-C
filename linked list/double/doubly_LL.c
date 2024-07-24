#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

void createList(struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}

void insertDouble(struct Node**head_ref, int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data=data;
    struct Node*temp=*head_ref;
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int main(){
    struct Node*head=NULL;
    insertDouble(&head,3);
    insertDouble(&head,4);
    insertDouble(&head,5);
    insertDouble(&head,6);
    insertDouble(&head,7);
    createList(head);

}