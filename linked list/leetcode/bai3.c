#include <stdio.h>
#include <stdlib.h>
// Input: head = [4,1,9,0]
// Output: [0,1,4,9]
//USING INSERTED SORT
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* sortedInsert(struct ListNode* head, struct ListNode* newNode) {
    if (head == NULL || head->val >= newNode->val) {
        newNode->next = head;
        head = newNode;
    } else {
        struct ListNode* current = head;
        while (current->next != NULL && current->next->val < newNode->val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Function to sort the linked list using insertion sort.
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* sorted = NULL; 
    struct ListNode* current = head; 

    while (current != NULL) {
        struct ListNode* next = current->next; 
        sorted = sortedInsert(sorted, current); 
        current = next;
    }

    return sorted;
}

// Function to print the linked list.
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = createNode(4);
    head->next = createNode(9);
    head->next->next = createNode(1);
    head->next->next->next = createNode(0);

    printf("Original List: ");
    printList(head);

    // Sort the linked list
    head = sortList(head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}
