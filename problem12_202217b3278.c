#include <stdio.h>
#include <stdlib.h>
 
// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
// Function prototypes
struct Node* createNode(int data);
struct Node* insertNode(struct Node* node, int data);
struct Node* searchNode(struct Node* root, int key);
struct Node* deleteNode(struct Node* root, int key);
struct Node* findDeepestRightmostNode(struct Node* root);
void inorderTraversal(struct Node* root);
void freeTree(struct Node* root);
 
int main() {
    struct Node* root = NULL;
    int elements[] = {45, 15, 79, 90, 10, 55, 12, 20, 50};
    int n = sizeof(elements) / sizeof(elements[0]);
 
    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        root = insertNode(root, elements[i]);
    }
 
    // Inorder traversal of the BST
    printf("Inorder traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");
 
    // Search for a node in the BST
    int key = 20;
    struct Node* foundNode = searchNode(root, key);
    if (foundNode != NULL) {
        printf("Element %d found in the BST.\n", key);
    } else {
        printf("Element %d not found in the BST.\n", key);
    }
 
    // Delete a node from the BST
    key = 79;
    root = deleteNode(root, key);
    printf("Inorder traversal after deleting %d:\n", key);
    inorderTraversal(root);
    printf("\n");
 
    // Free the memory allocated for the BST
    freeTree(root);
 
    return 0;
}
 
// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
// Function to insert a node in the BST
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}
 
// Function to search for a node in the BST
struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}
 
// Function to find the deepest rightmost node
struct Node* findDeepestRightmostNode(struct Node* root) {
    struct Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}
 
// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findDeepestRightmostNode(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    }
    return root;
}
 
// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
 
// Function to free the memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}