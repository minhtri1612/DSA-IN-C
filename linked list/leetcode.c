// Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
// Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
void insertnode(struct node** head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
void mergeInBetween(struct node** list1, int a, int b, struct node* list2) {
    struct node* current = *list1;
    struct node* predecessor = NULL;
    struct node* successor = NULL;
    for (int i = 1; i < a; i++) {
        predecessor = current;
        current = current->next;
    }
    for (int i = a; i <= b; i++) {
        current = current->next;
    }
    successor = current->next;
    if (predecessor != NULL) {
        predecessor->next = list2;
    } else {
        *list1 = list2;
    }
    while (list2->next != NULL) {
        list2 = list2->next;
    }
    list2->next = successor;
}
int main() {
    struct node* list1 = NULL;
    insertnode(&list1, 0);
    insertnode(&list1, 1);
    insertnode(&list1, 2);
    insertnode(&list1, 3);
    insertnode(&list1, 4);
    insertnode(&list1, 5);
    insertnode(&list1, 6);

    printf("list1 before merge: ");
    printList(list1);
    printf("\n");

    struct node* list2 = NULL;
    insertnode(&list2, 1000000);
    insertnode(&list2, 1000001);
    insertnode(&list2, 1000002);
    insertnode(&list2, 1000003);
    insertnode(&list2, 1000004);

    printf("list2: ");
    printList(list2);
    printf("\n");

    int a = 2;
    int b = 5;

    mergeInBetween(&list1, a, b, list2);

    printf("list1 after merge: ");
    printList(list1);
    printf("\n");

    return 0;
}
