#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

void createList( struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}

void insertAtTheEnd(struct Node**head_ref, int data){
    struct Node*newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    struct Node*current=*head_ref;
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}

void reverse(struct Node**head_ref){
    struct Node *prevNode = NULL;
    struct Node *currentNode = *head_ref;
    struct Node *nextNode = *head_ref;
    while(nextNode!=NULL){
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    *head_ref=prevNode;
}
int main(){
    struct Node*head=NULL;
    insertAtTheEnd(&head,3);
    insertAtTheEnd(&head,4);
    insertAtTheEnd(&head,1);
    insertAtTheEnd(&head,2);
    insertAtTheEnd(&head,5);
    insertAtTheEnd(&head,7);
    insertAtTheEnd(&head,8);
    createList(head);
    printf("\n");
    reverse(&head);
    createList(head);
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

}