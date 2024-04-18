//  Create a linked list contained numbers inputted from keyboard, but when we 
// insert a new node, we need to find appropriate position of the new node to guarantee that the original 
// list is a sorted list. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_sorted(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL || value < head->data) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void display() {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int value;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &value);
        insert_sorted(value);
        display();
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
