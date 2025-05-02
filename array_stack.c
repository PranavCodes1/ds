#include<stdio.h>

#define MAX_SIZE 50

int A[MAX_SIZE];
int top = -1; //stack is empty

void Push( int x){
    if(top == MAX_SIZE - 1)
{printf("Error:Staack Overflow \n");
return;
}
    top++;
    A[top]= x;
};

void pop(){
if (top == -1){
printf("Error:No element to pop\n");
return;
}
top--;

};

int Top(){
return A[top];
};


void print() {
    int i;
    printf("Stack: \n");
    for(i = 0;i<=top;i++){
        printf("%d",A[i]);
        printf("\n");

    }
}


int main (){

Push(2);print();
Push(1);print();
Push(12);print();
pop();print();
Push(8);print();


}