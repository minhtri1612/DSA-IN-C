//  Create a linked list contained numbers inputted from keyboard, but when we 
// insert a new node, we need to find appropriate position of the new node to guarantee that the original 
// list is a sorted list. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insert_sorted(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct Node* current = *head_ref;
    while (current->next != NULL && current->next->data < new_node->data) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

void display(struct Node*head) {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int num, data;
    
    printf("Enter number of elements to insert: ");
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        printf("Enter value: ");
        scanf("%d", &data);
        insert_sorted(&head, data);
        display(head);
    }

}
