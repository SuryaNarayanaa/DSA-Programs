#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int* initStack(int size,int**top){
    int* stack = (int*)malloc(sizeof(int)*size);
    if(stack == NULL)
    {
        printf("Error during malloc");
    }
    **top = -1;
    return stack;
}

int isEmpty( int top){
    if(top==-1)
    {
        return 1;
    }
    return 0;
}


int isFull(int top){
    if(top==MAX)
    {
        return 1;
    }
    return 0;
}

int* push(int* Stack,int data, int** top)
{
    if(isFull(**top))
    {
        printf("Stacfk overflow");
    }
    else{
        Stack[**top++]= data;
    }
    return Stack;
}

int* pop(int* Stack, int** top)
{
    if(isEmpty(**top))
    {
        printf("stack underflow");
    }
    else{
        **top--;
    }
    return Stack;
}
void display(int* Stack, int**top)
{
      for (int i = 0; i < **top; i++) {
                printf("%d",Stack[i]);
    }
}
int main()
{   int *top;
    int size =10;
    int* Stack = initStack(size,&top);
    for (int i = 0; i < 10; i++) {
        Stack = push(Stack, i, &top);
    }
    display(Stack, &top);
    
}