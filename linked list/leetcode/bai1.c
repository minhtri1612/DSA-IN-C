// Input: l1 = [3,5], l2 = [4,5,9,9]
// Output: [7,0,0,0,1]
// Explanation: 53 + 9954 = 10007.
#include <stdio.h>
#include <stdlib.h>

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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        struct ListNode* newNode = createNode(sum % 10);
        current->next = newNode;
        current = current->next;
    }
    
    return dummy.next;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode* l1 = createNode(3);
    l1->next = createNode(5);
    //l1->next->next = createNode(9);
    struct ListNode* l2 = createNode(4);
    l2->next = createNode(5);
    l2->next->next = createNode(9);
    l2->next->next->next=createNode(9);
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);
    freeList(l1);
    freeList(l2);
    freeList(result);
    
    return 0;
}
