#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(char data){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;

}

struct node *insert (struct node *root,char data){
    if(root == NULL){
        root = createnode(data);
}
else if(data <= root -> data){
    root -> left = insert(root -> left,data);
}
else {
    root -> right = insert(root -> right, data); 
}
return root;
}

void preorder(struct node *root) {

    if(root == NULL) return;

    printf("%c",root->data);
    preorder(root ->left);
    preorder(root ->right);

}

void inorder(struct node *root){
    if(root == NULL) return;

    inorder(root -> left);
    printf("%c",root -> data);
    inorder(root -> right);

}

void postorder(struct node *root){
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root-> right);
    printf("%c",root -> data);

}

int main() {
    /* Creating an example tree
                      M
                     / \
                    B   Q
                   / \   \
                  A   C   Z
    */
   
  struct node* root = NULL;
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}

