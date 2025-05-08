#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *right;
struct node *left;
};

struct node *FindMin(struct node *root){

    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
}

struct node *delete(struct node *root, int data){
    if(root == NULL) return root;

    else if(data < root -> data) root -> left = delete(root->left,data);
    else if(data > root -> data) root -> right = delete(root ->right,data);

    else{


        //case 1: no child

        if(root ->left && root -> right == NULL){
        free(root);
        root = NULL;
        }

        // case 2: one child
        else if(root -> left == NULL) {
            struct node *temp = root;
            root = root -> right;
            free(temp);
        }

        else if(root -> right == NULL){
        struct node *temp = root;
        root = root -> left;
        free(temp);

        }

      //case 3: 2 child

      else{

        struct node *temp = FindMin(root -> right);
        root -> data = temp -> data;
        root -> right = delete(root ->right,temp -> data);
      }

    }

    return root;  
}


void Inorder(struct node *root){
    if(root == NULL) return;

Inorder(root ->left);
printf("%d",root -> data);
Inorder(root -> right);
}


struct node* Insert(struct node *root,char data){
    if(root == NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root-> data = data;
        root -> left = root -> right = NULL;
        
    }
    else if (data <= root->data){
    root->left=Insert(root->left,data);
    }
    else root -> right = Insert(root ->right,data);

    return root;

}

int main () {

/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */

struct node *root = NULL;

root = Insert(root,5);
root = Insert(root,10);
root = Insert(root,3);
root = Insert(root,4);
root = Insert(root,1);
root = Insert(root,11);

root = delete(root,5);

printf("Inorder: ");
Inorder(root);
printf("\n");

return 0;

}

