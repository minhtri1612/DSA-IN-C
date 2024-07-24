#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node.
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to merge two sorted linked lists.
Node* merge(Node* p, Node* q) {
    // Base cases.
    if (p == NULL) return q;
    if (q == NULL) return p;

    Node* head = NULL;
    Node* sorting = NULL;

    // Initialize head and sorting pointers.
    if (p->data < q->data) {
        head = sorting = p;
        p = p->next;
    } else {
        head = sorting = q;
        q = q->next;
    }

    // Merge the remaining nodes.
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            sorting->next = p;
            sorting = p;
            p = p->next;
        } else {
            sorting->next = q;
            sorting = q;
            q = q->next;
        }
    }

    // Attach the remaining nodes.
    if (p != NULL) {
        sorting->next = p;
    } else {
        sorting->next = q;
    }

    return head;
}

// Function to create a new node.
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list.
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the linked list.
void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Main function to test the merge function.
int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(4);
    list1->next->next->next = newNode(6);
    list1->next->next->next->next = newNode(8);
    list1->next->next->next->next->next = newNode(9);

    list1->next->next->next->next->next->next = newNode(5);

    // Create second sorted linked list: 2 -> 4 -> 6
    Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    // Print the original lists.
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Merge the lists.
    Node* mergedList = merge(list1, list2);

    // Print the merged list.
    printf("Merged List: ");
    printList(mergedList);

    // Free the allocated memory.
    freeList(mergedList);

    return 0;
}
