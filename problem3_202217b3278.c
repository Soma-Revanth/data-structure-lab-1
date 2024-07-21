#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100  // Define the maximum size of the stack
 
// Define the stack and its top
typedef struct {
    int data[MAX];
    int top;
} Stack;
 
// Initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}
 
// Check if the stack is full (overflow)
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}
 
// Check if the stack is empty (underflow)
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
 
// Push an element onto the stack
void push(Stack *stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d\n", element);
    } else {
        stack->data[++stack->top] = element;
        printf("Pushed %d onto the stack\n", element);
    }
}
 
// Pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element\n");
        return -1;  // Return -1 to indicate an error
    } else {
        int poppedElement = stack->data[stack->top--];
        printf("Popped %d from the stack\n", poppedElement);
        return poppedElement;
    }
}
 
// Main function to demonstrate stack operations
int main() {
    Stack stack;
    initializeStack(&stack);
    
    int choice, element;
 
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
 
    return 0;
}