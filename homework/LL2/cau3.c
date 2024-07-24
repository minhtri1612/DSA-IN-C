//  Write functions to implement basic operations of a stack: 
// 1. Create an empty stack 
// 2. isEmpty() 
// 3. Pop an element at the top of a stack 
// 4. Push an element at the top of a stack 
// 5. Return value of the element at top of a stack 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct Node{
    int data;
    struct Node*next;
};
typedef struct Node*Stack;
// 1. Create an empty stack 
Stack createStack(){
    Stack S=malloc(sizeof(struct Node));
    S->next=NULL;
    return S;
}
// 2. isEmpty() 
int isEmpty(Stack S){
    return S->next==NULL;
}
// 3. Pop an element at the top of a stack 
int pop(Stack S){
    struct Node*temp=S->next;
    int popped = temp->data;
    S->next=S->next->next;
    free(temp);
    return popped;

}
// 4. Push an element at the top of a stack 
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
// 5. Return value of the element at top of a stack 
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
int evaluatePostfix(char* exp) {
    Stack S = createStack();
    int operand1, operand2;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(S, exp[i] - '0');
        } else {
            operand2 = pop(S);
            operand1 = pop(S);
            switch (exp[i]) {
                case '+':
                    push(S, operand1 + operand2);
                    break;
                case '-':
                    push(S, operand1 - operand2);
                    break;
                case '*':
                    push(S, operand1 * operand2);
                    break;
                case '/':
                    push(S, operand1 / operand2);
                    break;
            }
        }
    }

    int result = pop(S);
    freeStack(S);
    return result;
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
    // char exp[] = "235*+8-";
    // printf("Result of postfix evaluation: %d\n", evaluatePostfix(exp));
    // return 0;
}
