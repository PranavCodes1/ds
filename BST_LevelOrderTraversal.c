#include<stdio.h>
#include<stdlib.h>


struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct Queuenode{
    struct node *treenode;
    struct Queuenode *next;
};

struct Queue {
    struct Queuenode *front;
    struct Queuenode *rear;
};

struct node *Createnode(char data){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}

void enqueue(struct Queue *q,struct node *node){
struct Queuenode *temp = (struct Queuenode*)malloc(sizeof(struct Queuenode));
temp -> treenode = node;
temp -> next = NULL;
if(q -> rear == NULL){
    q -> front = q -> rear = temp;
}
else {
    q -> rear -> next = temp;
    q -> rear = temp;
}

}

struct node *dequeue(struct Queue *q){
    if(q -> front == NULL)
    return NULL;
    struct Queuenode *temp = q -> front;
    struct node *treenode = temp -> treenode;
    q -> front = q -> front -> next;
    if(q -> front == NULL)
    q -> rear = NULL;
    free(temp);
    return treenode;

}

int IsQueueEmpty(struct Queue *q){
    return q-> front == NULL;
}

void LevelOrder(struct node *root){
if(root == NULL) return;

struct Queue q;
q.front = q.rear = NULL;
enqueue(&q,root);

while (!IsQueueEmpty(&q)){

    struct node *current = dequeue(&q);
    printf("%c ",current->data);
    if(current->left != NULL)enqueue(&q,current->left);
    if(current->right != NULL)enqueue(&q,current->right);

}
}

struct node* Insert(struct node* root, char data) {
    if (root == NULL) {
        return Createnode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}


int main() {

  /*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */


    struct node* root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    
    LevelOrder(root);
    return 0;
}

