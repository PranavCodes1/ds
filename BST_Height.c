#include<stdio.h>
#include<stdlib.h>

struct Bstnode {

     int data;
     struct Bstnode *left;
     struct Bstnode *right;
};

struct Bstnode *GetNewNode(int data){
 struct Bstnode *newNode = (struct Bstnode *)malloc(sizeof(struct Bstnode));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

struct Bstnode *insert(struct Bstnode *root, int data){
    if(root == NULL){ //empty tree
    root = GetNewNode(data);
       
    }
    else if(data <= root -> data){
        root -> left = insert(root -> left, data);
    }

    else {
        root -> right = insert(root -> right,data);
    }
     return root;


}

int height(struct Bstnode* root) {
    if (root == NULL)
        return -1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main () {

struct Bstnode *root; //to store the address of root node

root = NULL; // setting tree as empty

root = insert(root,15);
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 25);
root = insert(root, 8);
root = insert(root, 12);

int treeHeight = height(root);
printf("Height of the binary tree: %d \n",treeHeight);
}