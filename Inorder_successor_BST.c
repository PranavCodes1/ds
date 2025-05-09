#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *Find(struct node *root,int data){

    if(root == NULL) return NULL;
    else if(root -> data == data) return root;
    else if(root -> data < data) return Find(root ->right,data);
    else return Find(root -> left,data);
}




struct node *FindMin(struct node *root){
if(root == NULL) return NULL;
while(root -> left != NULL){
    root = root -> left;
}
return root;
}

struct node *GetSuccessor(struct node *root, int data){
    struct node *current = Find(root,data);
    if(current == NULL) return NULL;

    //case 1: Node has right subtree

    if(current -> right != NULL){
       return FindMin(current -> right);

}
//case 2: No right Subtree

else{
    struct node *successor = NULL;
    struct node *ancestor = root;
    while(ancestor != current){
    if(current -> data < ancestor -> data){
            successor = ancestor;
            ancestor = ancestor->left;
    }
    else 
            ancestor = ancestor->right;

}
return successor;


}
}

void Inorder(struct node *root) {

 if(root == NULL) return;

    Inorder(root -> left);
    printf("%d ",root ->data);
    Inorder(root -> right);

};


struct node *Insert(struct node *root, int data){

    if(root == NULL){

        root = (struct node*)malloc(sizeof(struct node));
        root -> data = data;
        root -> left = root -> right = NULL;
    }

    else if(data <= root -> data){
        root -> left = Insert(root ->left,data);
    }

    else 
		root->right = Insert(root->right,data);
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

printf("Inorder traversal: ");
Inorder(root);
printf("\n");


struct node *successor = GetSuccessor(root,1);

if(successor == NULL){
    printf("No successor found \n");
}
else {
    printf("successor is %d \n", successor -> data);
}


}



