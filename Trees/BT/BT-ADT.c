#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
    int height;
}Tree;

Tree* createNode(int data)
{
    Tree* tree= (Tree*)malloc(sizeof(Tree));
    tree->data  =data;
    tree->left = NULL;
    tree->right = NULL;
    tree->height = 0;
    return tree;
}

Tree* insert(Tree* Root , int data)
{  
    if(Root == NULL)
    {
        return  createNode(data);;
    }
    if(Root->left== NULL)
    {
        Root->left = createNode(data);
    }
    else if (Root->right == NULL)
    {
        Root->right = createNode(data);
    }
    else{
        if(Root->left)
        {
            Root->left = insert(Root->left ,data);
        }
        else if(Root->right)
        {
            Root->right = insert(Root->right ,data);
        }
    }
    return Root;
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