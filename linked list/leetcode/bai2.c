// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    struct ListNode* temp = second->next;
    second->next = temp->next;
    free(temp);

    return dummy.next;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the linked list 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    // Remove the 2nd node from the end
    head = removeNthFromEnd(head, 2);

    printf("Modified List: ");
    printList(head);

    return 0;
}
