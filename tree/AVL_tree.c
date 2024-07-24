#include <stdio.h>
#include <stdlib.h>
struct AVLNode {
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};
int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}
struct AVLNode* createNode(int key) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;  
    return newNode;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct AVLNode* minvalue(struct AVLNode* root) {
    struct AVLNode* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct AVLNode* insert(struct AVLNode* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);


    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}
struct AVLNode*deleteNode(struct AVLNode*root, int key){
    if(root==NULL){
        return root;
    }
    if(key<root->key){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->key){
        root->right=deleteNode(root->right,key);
    }
    else{
        if((root->left==NULL)||(root->right==NULL)){
            struct AVLNode*temp=root->left?root->left:root->right;
            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else{// One child case
                *root=*temp;
            } 
            free(temp);
        }
        else// node with two children
        {
            struct AVLNode*temp=minvalue(root->right);
            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
        }
    }
    if (root == NULL)
      return root;
    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
void inOrder(struct AVLNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
int main() {
    struct AVLNode* root = NULL;
    root = insert(root, 9);
    root = insert(root, 27);
    root = insert(root, 50);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 21);
    root = insert(root, 36);
    root = insert(root, 41);
    printf("In-order traversal of the constructed AVL tree is:\n");
    inOrder(root);
    printf("\n");
    return 0;
}
