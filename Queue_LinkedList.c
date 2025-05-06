#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

//front and rear are the global variables to store the address of front and rear nodes.
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp-> data = x;
    temp -> next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear -> next = temp;
    rear = temp;
}

void dequeue() {

    struct node *temp =front;
    if(front == NULL){
        printf("Queue is empty \n");
        return;
    }
    if(front == rear){
            front = rear = NULL;
    }
    else {
        front = front -> next;
    }
    free(temp);

}

int Front (){
        if(front == NULL){
            printf("Queue is empty \n");
            return;
        }
        return front -> data;
}

void Print(){
    struct node *temp = front;
    while(temp != NULL) {
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main () {

    enqueue(5);Print();
    enqueue(9);Print();
    enqueue(3);Print();
    dequeue();Print();
    enqueue(7);Print();


    
}



