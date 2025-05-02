#include<stdio.h>
#include<stdlib.h>

 struct node {
    int data;
    struct node* next;
 };

 struct node *insert(struct node *head, int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node *temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }

    return head;
}


 void Reverseprint(struct node *p){

    if(p == NULL)
    { return; //exit condition
    }
    Reverseprint (p -> next); //recursive call
    printf("%d", p -> data); //first print the value in the node
    
 };

 int main () {
    struct node *head = NULL; //local variable
    head = insert(head,2);
    head = insert(head,4);
    head = insert(head,6);
    head = insert(head,5);
    
    Reverseprint(head);
    
return 0;
 }