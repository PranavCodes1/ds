#include<stdio.h>
#include<stdlib.h>


struct  node {
                int data;
                struct node *next;
 
              };

struct node *head; //global variable, accessible by all the functions

void insert(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void print()
{
         struct node *temp = head;
              printf("List is: ");

              while(temp !=  NULL)
              {
                printf("%d", temp -> data);
                temp = temp -> next;
              }
              printf("\n");
}

void delete(int n) //delete node at n position
                    {
                        struct node *temp1;
                        temp1 = head;
                        if(n == 1){

                            head = temp1 -> next; //head now points to second node.
                            free(temp1);
                            return;
                        }
                        for(int i = 0; i < n-2; i++)
                        temp1 = temp1 -> next;
                        // temp1 points to (n-1)th node
                        struct node *temp2;
                        temp2 = temp1 -> next; //nth node
                        temp1 -> next = temp2 -> next; //(n+1)th node
                        free(temp2); //delete temp2


                    }

int main (){
             head = NULL;
             insert(2);
             insert(4);
             insert(3);
             insert(5); //List : 2,4,3,5

             print();

             int n;
             printf("enter a position to delete:\n");
             scanf("%d",&n);

             delete(n);
             print();


            }


