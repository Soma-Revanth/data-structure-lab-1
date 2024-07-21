#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 100
 
typedef struct {
    int data[MAX_SIZE];
    int count;
} List;
 
void initialize(List *list) {
    list->count = 0;
}
 
int isFull(List *list) {
    return list->count == MAX_SIZE;
}
 
int isEmpty(List *list) {
    return list->count == 0;
}
 
void insert(List *list, int value, int position) {
    if (isFull(list)) {
        printf("List is full.\n");
        return;
    }
    if (position < 0 || position > list->count) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = list->count; i > position; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[position] = value;
    list->count++;
}
 
void delete(List *list, int value) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->data[i] == value) {
            break;
        }
    }
    if (i == list->count) {
        printf("Element not found.\n");
        return;
    }
    for (int j = i; j < list->count - 1; j++) {
        list->data[j] = list->data[j + 1];
    }
    list->count--;
}
 
void display(List *list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}
 
int main() {
    List list;
    initialize(&list);
    int option, value, position;
 
    while (1) {
        printf("\nOptions:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
 
        switch (option) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insert(&list, value, position);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                delete(&list, value);
                break;
            case 3:
                display(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
 
    return 0;
}