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

// Function to find the minimum value node in the BST
struct BSTNode* findMin(struct BSTNode* root) {
    struct BSTNode* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node in the BST
struct BSTNode* deleteNode(struct BSTNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct BSTNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to search for a node in the BST
bool search(struct BSTNode* root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to find the maximum value node in the BST
struct BSTNode* findMax(struct BSTNode* root) {
    struct BSTNode* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Function to print the BST in-order
void inOrder(struct BSTNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to print the BST pre-order
void preOrder(struct BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to print the BST post-order
void postOrder(struct BSTNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct BSTNode* root = NULL;
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 5);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    int target = 3;
    if (search(root, target)) {
        printf("%d is found in the BST.\n", target);
    } else {
        printf("%d is not found in the BST.\n", target);
    }

    struct BSTNode* min = findMin(root);
    printf("Min value: %d\n", min->data);

    struct BSTNode* max = findMax(root);
    printf("Max value: %d\n", max->data);

    root = deleteNode(root, 2);
    printf("In-order traversal after deleting 2: ");
    inOrder(root);
    printf("\n");

    return 0;
}
