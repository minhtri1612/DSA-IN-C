#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the BSTNode structure
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new BST node
struct BSTNode* getNewNode(int data) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct BSTNode* insert(struct BSTNode* root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the maximum value in the BST
int findMax(struct BSTNode* root) {
    if (root == NULL) {
        fprintf(stderr, "The tree is empty\n");
        exit(1); // Exit if the tree is empty
    }
    struct BSTNode* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

// Function to print the BST in-order
void inOrder(struct BSTNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 5);

    // Print the BST
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    // Find the maximum value in the BST
    int maxValue = findMax(root);
    printf("The maximum value in the BST is: %d\n", maxValue);

    return 0;
}
