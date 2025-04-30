#include<stdio.h>
#include<stdlib.h>



struct node {
                int data;
                struct node *next;
            };

 struct node *head;  //global variable

void insert(int data, int n) //function to insert data at nth position
                {
                   struct node *temp1 = (struct node*)malloc(sizeof(struct node));
                    temp1 -> data = data;
                    temp1 -> next = NULL;
                    if(n == 1) {
                                temp1 -> next = head;
                                head = temp1;
                                return;

                               }
                    struct node *temp2;
                    temp2 = head;
                    for(int i = 0;i<n-2;i++){
                                            temp2 = temp2 -> next;
                                            }

                    temp1 -> next = temp2 ->next;
                    temp2 -> next = temp1;
                };

void print(){ struct node *temp;
              while (temp != NULL) {
                                     printf("%d",temp -> data);
                                     temp = temp -> next;
                                    }
                printf("\n");                    
             };

 int main () {
                head = NULL; //empty list
                insert(5,1); //List :5
                insert(3,2); //List: 5,3
                insert(4,1); //list: 4,5,3
                
                print();
              }



                     

