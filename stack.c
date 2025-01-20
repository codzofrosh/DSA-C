#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct stackNode {
    struct node *top;
};

void initializeStack(struct stackNode *stack) {
    stack->top = NULL;
}

int isEmpty(struct stackNode *stack) {
    return stack->top == NULL;
}

void printStack(struct stackNode *stack) {
    struct node *current = stack->top;
    if (isEmpty(stack)) {
        printf("Stack Empty\n");
        return;
    }
    printf("Stack elements: ");
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void push(struct stackNode *stack) {
    char choice;
    do {
        struct node *stackInstance = (struct node *)malloc(sizeof(struct node));
        if (stackInstance) {
            printf("Enter element to be pushed: ");
            scanf("%d", &stackInstance->data);
            stackInstance->next = stack->top;
            stack->top = stackInstance;
            printf("Stack after pushing:\n");
            printStack(stack);
            printf("Do you want to push another element (y/n)? ");
            while (getchar() != '\n');
            scanf("%c", &choice);
        } else {
            printf("Memory not allocated\n");
            return;
        }
    } while (choice == 'Y' || choice == 'y');
}

void pop(struct stackNode *stack){
    if(isEmpty(stack)){
        printf("stack empty\n");
        return;
    }
    char choice;
    do {
        struct node *temp = stack->top;
        int popData = temp ->data;
        stack->top = stack->top->next;
        free(temp);
        printf("Popped Data %d\n",popData);
        printf("Stack after pop\n");
        printStack(stack);
        printf("Do u want to pop another element\n");
        while (getchar() != '\n');
        scanf("%c",choice);
    }while(choice == 'y'|| choice == 'Y');
    }
    
void stackOps(struct stackNode *stack) {
    int choice;
    printf("Enter Choice\n1. Push\n2. Pop\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
           
            break;
        case 2:
           
            break;
        default:
            printf("Enter correct choice\n");
            stackOps(stack);
            break;
    }
}

int main() {
    struct stackNode stack;
    initializeStack(&stack);
    //stackOps(&stack);
    push(&stack);
    pop(&stack);
    return 0;
}