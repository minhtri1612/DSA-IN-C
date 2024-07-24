#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct Node{
    int data;
    struct Node*next;
};
typedef struct Node*Stack;
Stack createStack(){
    Stack S=malloc(sizeof(struct Node));
    S->next=NULL;
    return S;
}
int isEmpty(Stack S){
    return S->next==NULL;
}
int pop(Stack S){
    struct Node*temp=S->next;
    int popped = temp->data;
    S->next=S->next->next;
    free(temp);
    return popped;
}
void push(Stack S, int data){
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    if(newNode==NULL){
        return;
    }
    else{
        newNode->next=S->next;
        S->next=newNode;
    }
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}
void infixToPostfix(const char *infix, char *postfix) {
    Stack stack = createStack();
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        
        if (isdigit(token)) {
            postfix[j++] = token;
        } else if (isOperator(token)) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(token)) {
                postfix[j++] = pop(stack);
            }
            push(stack, token);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
    freeStack(stack);
}


int peek(Stack S){
    return S->next->data;
}
void freeStack(Stack S) {
    while (S->next != NULL) {
        struct Node* temp = S->next;
        S->next = temp->next;
        free(temp);
    }
    free(S);
}


int main(){
    Stack S=createStack();
    push(S,3);
    push(S,4);
    push(S,2);
    printf("%d",peek(S));
    printf("\n");
    pop(S);
    printf("%d",peek(S));
    const char *infix = "5*4+6+7*2";
    char postfix[100];
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
}
