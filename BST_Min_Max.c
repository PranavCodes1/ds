#include<stdio.h>
#include<stdlib.h>

struct Bstnode {

     int data;
     struct Bstnode *left;
     struct Bstnode *right;
};

int FindMin(struct Bstnode *root){
    if(root == NULL){
        printf("Error:Tree is empty \n");
    return -1;
    }

    while(root -> left != NULL){
        root = root -> left;
    }
    return root -> data;

}

int FindMax(struct Bstnode *root){
if(root == NULL){
        printf("Error:Tree is empty \n");
    return -1;
    }
while(root -> right != NULL){
    root = root -> right;
}
return root-> data;
}

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

int main () {

struct Bstnode *root; //to store the address of root node

root = NULL; // setting tree as empty

root = insert(root,15);
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 25);
root = insert(root, 8);
root = insert(root, 12);

FindMax(root);
FindMin(root);
printf("Minimum value is: %d\n", FindMin(root));
printf("Maximum value is: %d\n", FindMax(root));



}
 