#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100  // Define the maximum size of the queue
 
// Define the queue and its front and rear
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;
 
// Initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}
 
// Check if the queue is full (overflow)
int isFull(Queue *queue) {
    return queue->rear == MAX - 1;
}
 
// Check if the queue is empty (underflow)
int isEmpty(Queue *queue) {
    return queue->rear < queue->front;
}
 
// Enqueue (insert) an element into the queue
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue %d\n", element);
    } else {
        queue->data[++queue->rear] = element;
        printf("Enqueued %d to the queue\n", element);
    }
}
 
// Dequeue (delete) an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue element\n");
        return -1;  // Return -1 to indicate an error
    } else {
        int dequeuedElement = queue->data[queue->front];
        for (int i = 0; i < queue->rear; i++) {
            queue->data[i] = queue->data[i + 1];
        }
        queue->rear--;
        printf("Dequeued %d from the queue\n", dequeuedElement);
        return dequeuedElement;
    }
}
 
// Display the queue
void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->data[i]);
        }
        printf("\n");
    }
}
 
// Main function to demonstrate queue operations
int main() {
    Queue queue;
    initializeQueue(&queue);
    
    int choice, element;
 
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                displayQueue(&queue);
                break;
            case 2:
                dequeue(&queue);
                displayQueue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
 
    return 0;
}
 