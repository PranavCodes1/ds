#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;  //stack is empty

void push (int x){

struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
temp -> data = x;
temp -> link = top;
top = temp;
}

void pop(){
struct node *temp;
if(top == NULL) return;
temp = top;
top = top -> link;
free(temp);
}

void print() {
    struct node *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


int main() {


push(2);print();
push(50);print();
push(23);print();
pop();print();

    
}