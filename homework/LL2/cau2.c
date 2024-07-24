// Write functions to implement basic operations of a doubly linked list: 
// 1. Create an empty doubly linked list 
// 2. Insert a node into doubly linked list 
// 3. Delete a node of doubly linked list 
// 4. Find a node of doubly linked list 
// 5. Sort the doubly linked list 
// After that writing a main function to test these functions. Assuming that doubly linked list will only 
// contain integer. 
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};
// 1. Create an empty doubly linked list 
struct Node*createNode(int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
//print DOUBLE LINKED LIST
void printDoubeLL(struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
// 2.1 Insert at the beginning a node into doubly linked list 
void insertBegin(struct Node**head_ref, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
}
// 2.2 Insert at the end a node into doubly linked list
void insertEnd(struct Node**head_ref, int data){
    struct Node* newNode = createNode(data);
    if(*head_ref==NULL){
        *head_ref = newNode;    
    }
    else{
        struct Node*current=*head_ref;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
        newNode->prev=current;
    }    
}
// 3.1 Delete beginning a node of doubly linked list 
void deleteBegin(struct Node**head_ref){
    struct Node*current=*head_ref;
    (*head_ref)=(*head_ref)->next;
    free(current);
}
// 3.2 Delete final a node of doubly linked list 
void deleteEnd(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    struct Node* temp = *head_ref;
    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}
// 4. Find a node of doubly linked list 
struct Node* findNode(struct Node**head_ref, int data){
    struct Node*current=*head_ref;
    while(current!=NULL &&current->data!=data){
        current=current->next;
    }
    return current;
}
// 5. Sort the doubly linked list 
void sortDoublyLinkedList(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main(){
    struct Node*head=NULL;
    insertBegin(&head,2);
    insertBegin(&head,8);
    insertBegin(&head,7);
    insertBegin(&head,0);
    insertEnd(&head,-4);
    insertEnd(&head,9);
    insertEnd(&head,6);
    insertEnd(&head,10);
    printDoubeLL(head);
    deleteBegin(&head);
    printDoubeLL(head);
    deleteEnd(&head);
    printDoubeLL(head);
    struct Node* foundNode = findNode(&head, 699);
    if (foundNode != NULL) {
        printf("Node with data 699 found.\n");
    } else {
        printf("Node with data 699 not found.\n");
    }
    sortDoublyLinkedList(&head);
    printDoubeLL(head);
  
}

