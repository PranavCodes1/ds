#include<stdio.h>
#include<stdlib.h>


struct node {

               int data;
               struct node *next;
            };
            
struct node *head;    // global variable,can be accessed anywhere

void insert(int x)
{
             struct node *temp;
             temp = (struct node *)malloc(sizeof(struct node));
             temp -> data = x;
             temp -> next = head;
             head = temp; // this stores the address of tempnode in head
             
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


int main (){
    
              head = NULL; //empty list
              int n,i,x;
              printf("Enter how many numbers you want to insert in the list: \n ");
              scanf("%d",&n);

              for (i = 0;i<n;i++) {
                printf("Enter the number \n");
                scanf("%d",&x);
                insert(x);
                print();
              }
             


            }