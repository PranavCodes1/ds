#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return createnode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool IsBSTUtil(struct node *root, int min, int max) {
    if (root == NULL) return true;

    if (root->data <= min || root->data > max) return false;

    return IsBSTUtil(root->left, min, root->data) &&
           IsBSTUtil(root->right, root->data, max);
}

bool IsBinarySearchTree(struct node *root) {
    return IsBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct node* root = NULL;
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 6);

    printf("%d\n", IsBinarySearchTree(root));
    return 0;
}
