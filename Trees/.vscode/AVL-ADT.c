#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right ;
    int height;

}Tree;


int maxVal(int a, int b)
{return (a > b) ? a : b;}

Tree* createNode(int data)
{
    Tree* t= (Tree*)malloc(sizeof(Tree));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    t->height = 1;
    return t;
}

int getHeight(Tree* root)
{
    if(root == NULL) return 0;
    return root->height;
}

int calcHeight(Tree* root)
{
    return maxVal(getHeight(root->left), getHeight(root->right)) +1;
}

Tree* rightrotate(Tree * root)
{
    Tree* c = root->left;
    Tree* t = c->right;
    c->right = root;
    root->left = t;

    c->height = calcHeight(c);
    root->height  =calcHeight(root);

    return c;
}

Tree* leftrotate(Tree * root)
{
    Tree* c = root->right;
    Tree* t = c->left;

    c->left= root;
    root->right = t;
    c->height = calcHeight(c);
    root->height  =calcHeight(root);
    

    return c;

}



int balanceFactor(Tree* root)
{
    return getHeight(root->left) - getHeight(root->right);
 
}

Tree* rotate(Tree * root)
{
    if(balanceFactor(root) >1)
    {
        if(balanceFactor(root->left)>0)
        {
            root = rightrotate(root);
        }
        else if (balanceFactor(root->left)<0)
        {
            root->left = leftrotate(root->left);
            root = rightrotate(root);
        }
    }
     if (balanceFactor(root)<-1)
    {
         if(balanceFactor(root->right)<0)
        {
            root = leftrotate(root);
        }
        else if (balanceFactor(root->right)>0)
        {
           root->right = rightrotate(root->right);
           root = leftrotate(root);
        }
    }

    return root;
}




Tree* insert(Tree* root , int data)
{
     if(root == NULL)
     {
        return createNode(data);
     }


     if(data < root->data)
     {
        root->left = insert(root->left ,data);
     }
     if(data > root->data)
     {
        root->right = insert(root->right ,data);
     }

    root->height = calcHeight(root);
    return rotate(root);

 
     
}


    void inorder(Tree* root) {
        if (root != NULL) {
            inorder(root->left);
            printf("%d ", root->data);
            inorder(root->right);
        }
    }

int main() {
    Tree* root = NULL;
    int arr[5] = {21, 26, 30, 9, 4};
    for (int i = 0; i < 5; i++) {
        root = insert(root, arr[i]);
    }

    printf("Root: %d\n", root->data);
    printf("Root Height: %d\n", root->height);
    printf("Root Balance Factor: %d\n\n\n", balanceFactor(root));
    rotate(root);

    inorder(root);

    return 0;
}