#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Stack
{
    Node* node;
    int top;
}Stack;

Node* createNode(int data)
{
    Node* newNode=  (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

}
Stack* initStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->node = NULL;
    stack->top =-1;
}

int isEmpty( Stack* stack)
{
    return stack->top != -1;
}
int isFull( Stack* stack)
{
    return stack->top == MAX-1;
}


Stack* push(Stack*stack, int data)
{
    if(isFull(stack))
    {
        printf("Stack Overflow");
    }
    else
    {
        Node* newNode=  createNode(data);
        if(stack == NULL)
        {
            stack->node = newNode;
        }
        else
        {
            newNode->next =stack->node;
            stack->node = newNode;
        }
        return stack;
    }
}


int pop(Stack*stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow");
    }
    else
    {
        Node* node = stack->node;
        int data = node->data;
        stack->node = stack->node->next;
        free(node);
        

        return data;
    }
}

int main()
{


Stack* stack = initStack();
for(int i = 1; i <= 10; i++) {
    stack = push(stack, i);
    printf("Pushed: %d\n", i);
}

for(int i = 1; i <= 5; i++) {
    if(!isEmpty(stack)) {
        printf("Popped: %d\n", pop(stack));
    }
}
return 0;
}