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
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
void printTree(struct Node* root, int space);
void freeTree(struct Node* root);
 
#define COUNT 10
 
int main() {
    struct Node* root = NULL;
    int elements[] = {45, 15, 79, 90, 10, 55, 12, 20, 50};
    int n = sizeof(elements) / sizeof(elements[0]);
 
    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        root = insertNode(root, elements[i]);
    }
 
    // Print the tree structure
    printf("Graphical representation of the BST:\n");
    printTree(root, 0);
    printf("\n");
 
    // In-order traversal
    printf("In-order traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n\n");
 
    // Pre-order traversal
    printf("Pre-order traversal of the BST:\n");
    preorderTraversal(root);
    printf("\n\n");
 
    // Post-order traversal
    printf("Post-order traversal of the BST:\n");
    postorderTraversal(root);
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
 
// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
 
// Function to perform preorder traversal of the BST
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
 
// Function to perform postorder traversal of the BST
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
 
// Function to print the tree structure
void printTree(struct Node* root, int space) {
    if (root == NULL)
        return;
 
    space += COUNT;
 
    printTree(root->right, space);
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    printTree(root->left, space);
}
 
// Function to free the memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}