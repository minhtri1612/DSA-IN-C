#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node*next;
};
void display(struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
void insertBegin(struct Node**head_ref, int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=*head_ref;
    *head_ref=newNode;
}
int tinhtong(struct Node**head_ref){
    struct Node*current=*head_ref;
    int sum=0;
    while(current!=NULL){
        sum+=current->data;
        current=current->next;
    }
    return sum;
}
void deleteBegin(struct Node**head_ref){
    struct Node*current=*head_ref;
    *head_ref=(*head_ref)->next;
    free(current);
}
void insertEnd(struct Node**head_ref, int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    struct Node*current=*head_ref;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}
void deleteEnd(struct Node**head_ref){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*current=*head_ref;
    while(current->next!=NULL){
        newNode=current;
        current=current->next;
    }
    if(current==*head_ref){
        *head_ref=NULL;
    }
    else{
        newNode->next=NULL;
    }
    free(current);
    
}
void insertPos(struct Node**head_ref, int data,int pos){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    struct Node*current=*head_ref;
    int i=1;
    while(i<pos){
        current=current->next;
        i++;
    }
    newNode->next=current->next;
    current->next=newNode;
}
void deletePos(struct Node**head_ref, int pos2){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*current=*head_ref;
    int i;
    while(i<pos2-1){
        current=current->next;
        i++;
    }
    newNode=current->next;
    current->next=newNode->next;
    free(newNode);
}
int main()
{
    struct Node*head=NULL;
    insertBegin(&head,3);
    insertBegin(&head,2);
    insertBegin(&head,1);
    display(head);
    insertEnd(&head,4);
    display(head);
    int pos;
    printf("nhap vi tri muon chen:");
    scanf("%d",&pos);
    insertPos(&head,6,2);
    display(head);
    printf("delete phan tu thu 1:");
    deleteBegin(&head);
    display(head);
    printf("\n");
    printf("xoa phan tu cuoi:");
    deleteEnd(&head);
    display(head);
    int pos2;
    printf("nhap vi tri muon xoa:");
    scanf("%d",&pos2);
    deletePos(&head,pos2);
    display(head);
    printf("\n");
    int tong=tinhtong(&head);
    printf("tong cua linked list:",tong);
    
}
