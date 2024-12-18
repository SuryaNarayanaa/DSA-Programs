#include<stdio.h>
#include<stdlib.h>
typedef struct  AVL
{
    int data;
    struct AVL* left;
    struct AVL* right;
    int height;
}AVL;


AVL* createNode(int data)
{
    AVL* newNode = (AVL*)malloc(sizeof(AVL));
    newNode->data = data;
    newNode->left  = NULL;
    newNode->right = NULL;
    newNode->height =1;
    return newNode;
}

int getHeight(AVL* root)
{   if(root == NULL )
    return 0;
    return root->height;
}

int calcHeight(AVL* root)
{
    return ((getHeight(root->left)>getHeight(root->right) )?( getHeight(root->left)) : (getHeight(root->right)) )+ 1;
}

int getBalanceFactor(AVL* root)
{
    return getHeight(root->left) - getHeight(root->right);

}

AVL* leftRotate(AVL* root)
{
       AVL* C = root->right;
    AVL* T = C->left;

    C->left  =root;
    root->right = T;
    C->height = calcHeight(C);
    root->height = calcHeight(root);

    return C; // new  root
  
}


AVL* rightRotate(AVL* root)
{

      AVL* C = root->left;
    AVL* T = C->right;

    C->right  =root;
    root->left = T;
    C->height = calcHeight(C);
    root->height = calcHeight(root);

    return C; // new  root

  
}


AVL* rotate(AVL* root)
{

    // left case
    if(getBalanceFactor(root) > 0 )
    {   // LL CASE 
        if(getBalanceFactor(root->left) > 0 )
        {
         root =  rightRotate(root);
        }
        // LR CASE
        else if(getBalanceFactor(root->left)<0)
        {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    // right case
    if(getBalanceFactor(root) < 0 )
    {
        // RR CASE 
        if(getBalanceFactor(root->right) < 0 )
        {
         root =  leftRotate(root);
        }
        // RL CASE
        else if(getBalanceFactor(root->right)>0)
        {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

return root;

}

AVL* insert(AVL* root , int data)
{
    if(root == NULL)
        return createNode(data);

    if(data  < root->data)
    {
        root->left =  insert(root->left , data);
    }
     if(data > root->data)
    {
        root->right =  insert(root->right , data);
    }

    root->height  = calcHeight(root);
    return rotate(root);
}





void inOrder(AVL* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    AVL* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal of the constructed AVL tree is \n");
    inOrder(root);

    return 0;
}
