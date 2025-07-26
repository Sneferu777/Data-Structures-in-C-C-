#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node* node){
    return node ? node->height : -1;
}

int height1(struct node* root) {
    if (!root) return -1;
    int lh = height1(root->left);
    int rh = height1(root->right);
    return 1 + max(lh, rh);
}

int getBalance(struct node* node) {
    return node ? height(node->right) - height(node->left) : 0;
}

struct node* CreateNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->height = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(struct node** root, int data) {
    if (*root == NULL) {
        *root = CreateNode(data);
        return;
    }

    if (data < (*root)->data)
        insert(&((*root)->left), data);
    else if (data > (*root)->data)
        insert(&((*root)->right), data);
    else
        return; // duplicate

    (*root)->height = 1 + max(height((*root)->left), height((*root)->right));
}

void inOrder(struct node* root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node* search(struct node* root, int data) {
    if (root == NULL) return NULL;
    if (data == root->data) return root;
    else if (data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

int findMin(struct node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

int main() {
    struct node* root = NULL;
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 10);
    insert(&root, 40);
    insert(&root, 590);
    insert(&root, 390);
    insert(&root, 1000);
    insert(&root, 15);

    int balance = getBalance(root);
    printf("\nBalance of root (%d) = %d\n", root->data, balance);
    puts((balance == 0) ? "Balanced" : "Not Balanced");

    printf("InOrder: ");
    inOrder(root);
    puts("");

    int number;
    puts("Enter the value to search for:");
    scanf("%d", &number);

    struct node* result = search(root, number);
    puts(result == NULL ? "NOT FOUND" : "FOUND");

    printf("Height of right subtree = %d\n", height1(root->right));
    printf("The MIN = %d\n", findMin(root));

    return 0;
}
