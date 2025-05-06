#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

struct Bstnode *insert(struct Bstnode *rootPtr, int data){
    if(rootPtr == NULL){ //empty tree
    rootPtr = GetNewNode(data);
       
    }
    else if(data <= rootPtr -> data){
        rootPtr -> left = insert(rootPtr -> left, data);
    }

    else {
        rootPtr -> right = insert(rootPtr -> right,data);
    }
     return rootPtr;


}



bool search(struct Bstnode *rootPtr, int data){
if(rootPtr == NULL) return false;
else if(rootPtr -> data == data) return true;
else if(data <= rootPtr -> data) return search(rootPtr -> left,data);
else return search(rootPtr -> right, data);
}


int main () {

struct Bstnode *rootPtr; //to store the address of root node

rootPtr = NULL; // setting tree as empty

rootPtr = insert(rootPtr, 15);
rootPtr = insert(rootPtr, 10);
rootPtr = insert(rootPtr, 20);
rootPtr = insert(rootPtr, 25);
rootPtr = insert(rootPtr, 8);
rootPtr = insert(rootPtr, 12);


int number;
printf("Enter a number to be searched \n");
scanf("%d",&number);
if(search(rootPtr,number) == true){
    printf("found \n");
} else{
printf("Not found \n");
}

}
 
 