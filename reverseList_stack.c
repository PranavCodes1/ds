#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct StackNode {
    struct Node* data;
    struct StackNode* next;
};


void pushStack(struct StackNode** top_ref, struct Node* node) {
    struct StackNode* new_node = (struct StackNode*) malloc(sizeof(struct StackNode));
    new_node->data = node;
    new_node->next = *top_ref;
    *top_ref = new_node;
}

struct Node* popStack(struct StackNode** top_ref) {
    if (*top_ref == NULL)
        return NULL;

    struct StackNode* temp = *top_ref;
    struct Node* res = temp->data;
    *top_ref = temp->next;
    free(temp);
    return res;
}

int isStackEmpty(struct StackNode* top) {
    return top == NULL;
}

void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reverseUsingStack(struct Node** head_ref) {
    struct StackNode* stack = NULL;
    struct Node* current = *head_ref;

    // Push all nodes to stack
    while (current != NULL) {
        pushStack(&stack, current);
        current = current->next;
    }

    // Reconstruct the list from stack
    if (isStackEmpty(stack)) return;

    *head_ref = popStack(&stack);
    current = *head_ref;

    while (!isStackEmpty(stack)) {
        current->next = popStack(&stack);
        current = current->next;
    }
    current->next = NULL; 
}


int main() {
    struct Node* head = NULL;

    // List: 40 -> 30 -> 20 -> 10
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    printf("Original Linked List:\n");
    printList(head);

    reverseUsingStack(&head);

    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}

