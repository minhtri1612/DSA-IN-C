#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Example 1:
// Input: s = "()"
// Output: true
// Example 2:
// Input: s = "()[]{}"
// Output: true
// Example 3:
// Input: s = "(]"
// Output: false
struct StackNode {
    char data;
    struct StackNode* next;
};

struct StackNode* createStackNode(char data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

bool isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, char data) {
    struct StackNode* stackNode = createStackNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

char pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        return '\0';
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

char peek(struct StackNode* root) {
    if (isEmpty(root)) {
        return '\0';
    }
    return root->data;
}

bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosingBracket(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isValid(char* s) {
    struct StackNode* stack = NULL;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isOpeningBracket(s[i])) {
            push(&stack, s[i]);
        } else if (isClosingBracket(s[i])) {
            if (isEmpty(stack) || !isMatchingPair(pop(&stack), s[i])) {
                return false;
            }
        }
    }
    return isEmpty(stack);
}

// Main function to test the isValid function.
int main() {
    char* test1 = "()";
    char* test2 = "()[]{}";
    char* test3 = "(]";

    printf("Input: %s\nOutput: %s\n\n", test1, isValid(test1) ? "true" : "false");
    printf("Input: %s\nOutput: %s\n\n", test2, isValid(test2) ? "true" : "false");
    printf("Input: %s\nOutput: %s\n\n", test3, isValid(test3) ? "false" : "false");

    return 0;
}
