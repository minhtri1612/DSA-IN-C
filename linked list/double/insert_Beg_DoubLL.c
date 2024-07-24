#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

void printList(struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}

void insert_Beginning(struct Node**head_ref, int data){
    struct Node*newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    
    if(*head_ref==NULL){
        *head_ref = newNode;    
    }
    else{
        struct Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int main(){
    struct Node*head= NULL;
    insert_Beginning(&head,3);
    insert_Beginning(&head,4);
    insert_Beginning(&head,1);
    insert_Beginning(&head,6);
    insert_Beginning(&head,2);
    printList(head);
}
