#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

struct node{
        int info;
        struct node *link;
}
    *start;

    void create(int);
    void display();
    void insert_end(int);
   int main () {

        int choice,data,no_of_node,choice1;

        start = NULL;
        while (1)
        {
            system ("cls");

            printf("1.Create Linked List \n");
            printf("2. Display linked list \n");
            printf("3.Exit \n");

            printf("Enter your choice: ");
            scanf("%d",&choice);
            switch (choice)
        {
            case 1: printf("Enter no of nodes to be created: ");
            scanf("%d",&no_of_node);
            create(no_of_node);
            break;

            case 2: display();
            break;

            case 3: system("cls");
            printf("1.insert the node at the end of list: \n");
            printf("Enter your choice:");
            scanf("%d",&choice1);

        switch(choice1)
        {
        case 1: printf("Enter data for node: ");
                scanf("%d",&data);
                insert_end(data);
                break;
        case 2: exit(1);
        default:printf("Invalid entry");
        }
        }
        }
    }
        void create(int no)
        {
            int i,data;
            system("cls");
            struct node *temp;
            temp = (struct node *)malloc(sizeof(struct node));
            for(i=0;i<no;i++)
            {
                if(start == NULL)
                {
                    printf("Enter data for node %d: ",i);
                    scanf("%d",&data);
                    temp -> info = data;
                    temp -> link  = NULL;                
                    start = temp;
                }
                else{
                    printf("Enter data for node %d:",i);
                    scanf("%d",&data);
                    insert_end(data);

                }
                }
                if (no>0){
                printf("List created");
                }
                else{
                    printf("list not created");
                }
                getchar();
                system("cls");

        }
    

    void display()
    {
        struct node *ptr;
        ptr = start;
        system("cls");
        if(start == NULL)
        {
            printf("List is empty");
            getchar();
            return;

        }

       printf("Linked list \n");
        while(ptr != NULL)
        {
            printf("%d ->",ptr -> info);
            ptr = ptr->link;
        }

        printf("End of list");
        getchar();
        system("cls");
    }

void insert_end(int data)
{
    struct node *ptr,*tempnode;
    ptr = start;
    while(1)
    {
        if (ptr -> link != NULL)
        ptr = ptr -> link;
        else
        break;
    }
    tempnode = (struct node*)malloc(sizeof(struct node));
    tempnode -> info = data;
    tempnode -> link = NULL;
    ptr -> link = tempnode;

}




    