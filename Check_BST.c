#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {

    int data;
    struct node *left;
    struct node *right;
};
bool IsSubtreeLesser(struct node *root, int value){

if(root == NULL){ return true;}
if(root -> data <= value && IsSubtreeLesser(root -> left,value) && IsSubtreeLesser(root -> right,value))
{
    return true;
}
else{
    return false;
};
}

bool IsSubtreeGreater(struct node *root, int value){

if(root == NULL){ return true;}
if(root -> data >value && IsSubtreeGreater(root -> left,value) && IsSubtreeGreater(root -> right,value))

    return true;

else
    return false;

}

struct node *createnode(int  data){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;

}

struct node *insert (struct node *root,int  data){
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


bool IsBinarySearchTree(struct node *root) {
    if (root == NULL) return true;

    if (IsSubtreeLesser(root->left, root->data) &&
        IsSubtreeGreater(root->right, root->data) &&
        IsBinarySearchTree(root->left) &&
        IsBinarySearchTree(root->right)) {
        return true;
    } else {
        return false;
    }
}


int main () {

  /*Code To Test the logic
	  Creating an example tree
	            7
			   / \
			  4   9
			 / \    
			1   6   
    */


    struct node* root = NULL;
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 6);
    
    printf("%d\n", IsBinarySearchTree(root));
}


 