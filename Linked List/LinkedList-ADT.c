#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
}Node;




Node* createNode(int data)
{
    Node* node= (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;


    return node;
    
} 


int findLength (Node* head)
{
    int count=0;
    Node* curr = head;
    while(curr!= NULL)
    {
        count++;
        curr  = curr->next;
    }

    return count;
}


void displayNode(Node* head)
{
    Node* curr = head;
    while(curr!=NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n\n");
}


Node* traverse(Node * head)
{   Node* curr = head;
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }

    return curr;
}


Node* traverseToPosition(Node* head, int index)
{
    Node* curr = head;
    int count =2;
    while(count<index)
    {
            curr = curr->next;
            count++;      
    }

    return curr;
}



Node* insertAtEnd(Node* head,int data)
{   Node* nodeToInsert = createNode(data);

    if (head==NULL)
    {
        return nodeToInsert;
    }

    Node* endNode=  traverse(head);
    endNode->next = nodeToInsert;

    return head;
}


Node* inserAtBeginning(Node* head, int data)
{
    Node* nodeToInsert = createNode(data);
    nodeToInsert->next = head;

    return nodeToInsert;
}


Node* insertAtIndex(Node* head, int index , int data)
{
    Node* nodeToInsert = createNode(data);
    Node* curr = traverseToPosition(head, index);
    Node* nextNode = curr->next;
    curr->next =nodeToInsert;
    nodeToInsert->next = nextNode;


    return head;
}


Node* deleteAtBeginning(Node* head)
{
    head= head->next;
    return head;
}

Node* deleteAtEnd(Node* head)
{   Node* curr  = head;
    if (curr==NULL) return NULL;
    if (curr->next == NULL) curr = NULL;


    while(curr->next->next != NULL)
    {
        curr= curr->next;
    }

    curr->next = NULL;
    return head;
}


Node* deleteAtPosition(Node* head, int position)
{   if (head ==NULL) return NULL;
    if(head->next== NULL  && position ==1) 
    {
        head =NULL;  
        return head;
    }
    else if (head->next == NULL)
    {return NULL;}

  
    Node* previousNode = traverseToPosition(head, position);
    Node* NodeToDelete = previousNode->next;
    previousNode->next = NodeToDelete->next;
    



    return head;


    
}
int main()
{
int len, elem, position;
printf("Enter the length of the Linked List : ");
scanf("%d", &len);



Node* head= NULL;


for (int i=1 ;i<=len; i++)
{
    printf("Enter the Element %d", i);
    scanf("%d", &elem);
    head = insertAtEnd(head, elem);

}



    // printf("Enter the Element to add at beginning : ");
    // scanf("%d", &elem);
    // head = inserAtBeginning(head, elem);


    // printf("Enter the position to insert : ");
    // scanf("%d", &position);
    // printf("Enter the element to insert : ");
    // scanf("%d", &elem);
    // head = insertAtIndex(head, position, elem);

    //head = deleteAtBeginning(head);

    // head  = deleteAtEnd(head);

    printf("Enter the position to delete : ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nLenght of the linked list: %d\n\n\n", findLength(head));




displayNode(head);




}