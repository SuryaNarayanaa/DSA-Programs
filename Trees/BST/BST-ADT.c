#include<stdio.h>
#include<stdlib.h>

typedef struct  Tree
{
    /* data */
    int data;
     struct Tree* left;
      struct Tree* right;
}Tree;

Tree* createNode(int data)
{
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->data= data;
    t->left =NULL;
    t->right = NULL;
    return t;
}


Tree* insert(Tree*  tree, int data)
{
    if(tree ==NULL)
    {return createNode(data);}

    if(data < tree->data)
    {
        tree->left = insert(tree->left ,data);
    }
    if(data > tree->data)
    {
        tree->right = insert(tree->right ,data);
    }
    return tree;
    

}




    void inorder(Tree* root) {
        if (root != NULL) {
            inorder(root->left);
            printf("%d ", root->data);
            inorder(root->right);
        }
    }

int main()
{
    Tree* root = NULL;
    int elements[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }


    inorder(root);
    return 0;
}