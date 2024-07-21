#include <stdio.h>
#define MAX 10
 
int queue[MAX];
int front = 0;
int rear = -1;
 
void displayQueue() {
    if (rear < front) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
 
void insertElement(int element) {
    if (rear < MAX - 1) {
        rear++;
        queue[rear] = element;
        printf("Inserted %d\n", element);
        displayQueue();
    } else {
        printf("Queue is full\n");
    }
}
 
void deleteElement() {
    if (rear < front) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        for (int i = front; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        displayQueue();
    }
}
 
int main() {
    int choice, element;
 
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(element);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}