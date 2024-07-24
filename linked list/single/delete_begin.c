#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
void printList(struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}

void insertBeginning(struct Node**head_ref, int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->next=*head_ref;
    *head_ref=newNode;
}

void deleteBegin(struct Node**head_ref){
    struct Node*temp=*head_ref;
    (*head_ref)=(*head_ref)->next;
    free(temp);
}

int main(){
    struct Node*head= NULL;
    insertBeginning(&head,2);
    insertBeginning(&head,3);
    insertBeginning(&head,4);
    insertBeginning(&head,5);
    insertBeginning(&head,6);
    deleteBegin(&head);
    printList(head);

}