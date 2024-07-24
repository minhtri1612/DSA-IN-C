#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

void createList(struct Node*head){
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


void deletePos(struct Node**head_ref,int pos){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*temp=*head_ref;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newNode=temp->next;
    temp->next=newNode->next;
    free(newNode);
}
int main(){
    int pos;
    printf("nhap vi tri muon xoa:");
    scanf("%d",&pos);
    struct Node*head=NULL;
    insertAtTheEnd(&head,2);
    insertAtTheEnd(&head,3);
    insertAtTheEnd(&head,4);
    insertAtTheEnd(&head,5);
    insertAtTheEnd(&head,6);
    insertAtTheEnd(&head,7);
    createList(head);
    printf("\n");
    deletePos(&head,pos);
    createList(head);

}