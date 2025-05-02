#include<stdio.h>
#include<stdlib.h>


struct node {

    int data;
    struct node *next;
    struct node *prev;

};
struct node *head;

struct node *GetNewNode(int x){
struct node *newnode;
newnode = (struct node*)malloc(sizeof(struct node));

newnode -> data = x;
newnode -> prev = NULL;
newnode ->next = NULL;
return newnode;

}



void insert_at_head(int x){

struct node *newnode = GetNewNode(x);
if (head == NULL){
    head = newnode;
    return;
}
head -> prev = newnode;
newnode -> next = head;
head = newnode;


}

void InsertAtTail(int x) {
	struct node *temp = head;
	struct node *newnode = GetNewNode(x);
	if(head == NULL) {
		head = newnode;
		return;
	}
	while(temp -> next != NULL) temp = temp->next; // Go To last Node
	temp->next = newnode;
	newnode->prev = temp;
}

void print(){

    struct node *temp = head;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d",temp -> data);
        temp = temp -> next;

    }
    printf("\n");
}

void reversePrint() {

    struct node *temp = head;
    if(temp == NULL) return; //empty list, exit
    //going to last node
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    //traversing backward using prev pointer
    printf("Reverse: ");
    while(temp != NULL){
        printf("%d", temp -> data);
        temp = temp -> prev;
    }
    printf("\n");
}



int main () 
{
head = NULL; 
insert_at_head(2); print();reversePrint();
insert_at_head(3);print();reversePrint();
insert_at_head(9);print();reversePrint();
InsertAtTail(8);print();reversePrint();
InsertAtTail(1);print();reversePrint();
}
