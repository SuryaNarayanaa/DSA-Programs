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



Node* reverseLinkedList(Node* head)
{
    Node* prev  = NULL;
    Node* curr = head;
    Node* next ;

 while(curr != NULL)
 {
     next  = curr->next;
     curr->next = prev;

     prev = curr;
     curr = next;

 }

 return prev;
}
Node* removeDuplicatesInSortedLL(Node* head)
{
    Node* curr= head;
    int element =1;
    while(curr->next!=NULL)
    {
        if(curr->data == curr->next->data)
        {
            deleteAtPosition(head , element);

        }
        curr = curr->next;
        element++;
    }
    return head;


}

Node* merge2LLIntoALternateLL(Node* head1, Node* head2)
{
    Node* mergedLL= NULL ;
    Node*  curr1=head1;
    Node*  curr2 =head2 ;
    Node* mergedHead =NULL;
    int curr1Data, curr2Data;
    if (curr1 == NULL) return curr2;
    if (curr2== NULL ) return curr1;
    while(curr1 && curr2)
    {
        curr1Data = curr1->data;
        curr2Data = curr2->data;
        if(mergedLL != NULL)
        {

            mergedLL = insertAtEnd(mergedLL , curr1Data);
            mergedLL =insertAtEnd(mergedLL , curr2Data);
        }
        else
        {
             mergedHead = insertAtEnd(mergedLL , curr1Data);
            mergedLL =insertAtEnd(mergedHead , curr2Data);

        }


        curr1 = curr1->next;
        curr2= curr2->next;

    }
    if(curr1)
    { mergedLL->next = curr1;
    }
    else if(curr2)
    {

        mergedLL->next = curr2;
    }

    return mergedHead;
}


Node* sortTernary(Node* head)
{
    Node* curr = head;
    int cnt[3] = {0},  pos ,count , ind=0;
    while(curr!=NULL)
    {
        cnt[curr->data]++;
        curr = curr->next;
    }
    curr = head;
    while(curr!= NULL)
    {
        if(cnt[ind]==0 )
        {
         ind++;
        }
        else{
            curr->data = ind;
            cnt[ind]--;
            curr = curr->next;
        }
    }
    return head;
    }


int main()
{
int len, elem, position;
printf("Enter the length of the Linked List 1 : ");
scanf("%d", &len);



Node* head1= NULL ;
Node* head;


for (int i=1 ;i<=len; i++)
{
    printf("Enter the Element %d", i);
    scanf("%d", &elem);
    head1 = insertAtEnd(head1, elem);

}
printf("Enter the length of the Linked List 2 : ");
scanf("%d", &len);


/*

Node* head2= NULL;


for (int i=1 ;i<=len; i++)
{
    printf("Enter the Element %d", i);
    scanf("%d", &elem);
    head2 = insertAtEnd(head2, elem);

}

*/
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

    //printf("Enter the position to delete : ");
    //scanf("%d", &position);

    //head = deleteAtPosition(head, position);

    //printf("\nLenght of the linked list: %d\n\n\n", findLength(head));


    //head =  removeDuplicatesInSortedLL(head);
    //head = merge2LLIntoALternateLL(head1 ,head2);

    head = sortTernary(head1);




displayNode(head1);

}
