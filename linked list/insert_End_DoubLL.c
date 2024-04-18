#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

void printLIst(struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}

void insertTheEnd(struct Node**head_ref, int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    struct Node*temp=*head_ref;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
}