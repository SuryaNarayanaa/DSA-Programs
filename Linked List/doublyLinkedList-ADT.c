#include <stdio.h>
#include <stdlib.h>




typedef struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;

}Node;




Node* traverse(Node* head)
{
    Node* curr = head;
    while(curr->next!=NULL)
    {

        curr = curr->next;
    }
    return curr;

}


Node* traverseToIndex(Node* head , int index)
{    Node* curr = head;
    int count =1;
    for(count =1 ; count <index-1 ; count++)
    {

        curr = curr->next;
    }
    return curr;
}


Node* createNode(int data)
{
    Node* head = (Node *)malloc(sizeof(Node));
    head->prev = NULL;
    head->data = data;
    head->next = NULL;

    return head;

}

Node* insertAtBeginning(Node* head ,int data)
{
    Node* createdNode = createNode(data);
    head->prev = createdNode;
    createdNode->next = head;

    head = createdNode;
    return head;

}

Node* insertAtMiddle(Node* head , int data , int pos)
{
    Node* createdNode = createNode(data);
    Node*  prevNode=traverseToIndex(head , pos);
    Node*  nextNode= prevNode->next;

    createdNode->next = nextNode;
    createdNode->prev = prevNode;

    prevNode->next =createdNode;
    nextNode->prev = createdNode;


    return head;


}
Node* insertAtEnd(Node* head, int data)
{       Node* createdNode = createNode(data);
        if (head == NULL)
        {
            return createdNode;
        }
        Node* endNode = traverse(head);

        createdNode->prev = endNode;
        createdNode->next = NULL;
        endNode->next = createdNode;
        return head;
}

Node* deleteAtBeginning(Node* head)
{
    head->next->prev= NULL;
    head = head->next;
    return  head;

}


Node* deleteAtIndex(Node* head , int index)
{
    Node* nodeToDelete = traverseToIndex(head , index);

    Node* prevNode = nodeToDelete->prev;
    Node* nextNode = nodeToDelete->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    return head;



}



Node* deleteAtEnd(Node* head)
{
    Node* endNode= traverse(head);
    endNode->prev->next= NULL;
    endNode->prev = NULL;
    return head;
}



void displayNodeFromHead(Node* head)
{

    Node* curr = head;
    while(curr!=NULL)
    {
        printf("%d->",curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

}


void displayNodeFromTail(Node* tail)
{

    Node* curr = tail;
    while(curr!=NULL)
    {
        printf("%d->",curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");

}





int main()
{
    int i,len ,data;
    printf("Enter the initial number of elements : ");
    scanf("%d" , &len);

     Node* head= NULL;

    for(i=0 ; i<len ;i++)
    {   printf("Enter the data for position %d : ", i+1);
        scanf("%d", &data);
       head = insertAtEnd(head , data);

    }



    //printf("Enter the element to insert at the beginning :");
    //scanf("%d" ,&data);
    //head = insertAtBeginning(head , data);
    //head = insertAtMiddle(head , data , 3);
    //head = deleteAtBeginning(head);
    //head = deleteAtEnd(head);
    //head = deleteAtIndex(head , 3+1);


        Node* tail =traverse(head);


    displayNodeFromHead(head);
    displayNodeFromTail(tail);
}
