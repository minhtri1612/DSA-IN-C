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
    printf("\n");
}
void insertAtTheBeginning(struct Node**head_ref, int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=*head_ref;
    *head_ref=newNode;
}
int main(){
    struct Node*head= NULL;
    insertAtTheBeginning(&head,3);
    insertAtTheBeginning(&head,2);
    insertAtTheBeginning(&head,1);
    insertAtTheBeginning(&head,7);
    insertAtTheBeginning(&head,8);
    insertAtTheBeginning(&head,9);
    printList(head);
}