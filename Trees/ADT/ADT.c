#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data; 
    struct Node* left;
    struct Node* right;    
}Node;

Node* createNode(int data)
{
    Node* newNode =(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}
Node* insertNode(Node* root , int data){
    if(root == NULL){
        root= createNode(data);

    }
    else{
            Node* node = createNode(data);
            if(data < root->data){
                root->left = insertNode(root->left, data);
            }
            else{
                root->right = insertNode(root->right, data);
            }

    }
    return root;
    
}
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main(){
    Node* root= NULL;
    for (int i =0;i<10;i++){
        int data;
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    preorderTraversal(root);


}