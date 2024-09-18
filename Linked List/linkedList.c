#include<stdio.h>
#include<stdlib.h>
#include"LinkedList-ADT.c"
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node * create_node(int data)
{
    Node * node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}
void print_list(Node *node)
{
    while(node)
    {
        printf("%d ->", node->data);
        node = node->next;
    }
    return ;

}


Node * insert_at_first(Node *node , int data)
{
    Node *new_node = create_node(data);
    new_node->next = node;
    return new_node;

}

Node * insert_at_index(Node*head , int data , int index)
{
    Node* new_node = create_node(data);
    Node * ptr  = head;
    int i=0; 
    while (i!=index-1)
    {
        ptr = ptr->next;
        i++;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return head;
    
}
Node * insert_at_end(Node *head , int data)
{
    Node * new_node = create_node(data);
    Node * ptr = head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next  = new_node;
    return head;



}

Node * insert_after_node(Node *head , int data , Node *prev_node)
{
   Node * new_node = create_node(data);
   Node * p = head;
   while(p!=prev_node)
   { 
    p= p->next;
   }
   new_node->next= p->next;
   p->next = new_node;
   return head;

}
int main()
{

Node *head = create_node(1);
Node *second = create_node(2);
Node *third = create_node(3);
head->next = second;
second->next = third;
third->next = NULL;
head = insert_at_first(head , 0);
head = insert_at_index(head , 9876543,2);
head = insert_at_end(head, 90);

head = insert_after_node(head , 100 , second);
print_list(head);





}