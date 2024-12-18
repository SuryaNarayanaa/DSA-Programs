#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;  // Added height variable
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;  // A new node is initially at height 1
    return newNode;
}

// Helper function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Update the height of a node
void updateHeight(Node* node) {
    if (node != NULL) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Update the height after insertion
    updateHeight(root);
    return root;
}

// Function to perform an inorder traversal
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d (Height: %d) ", root->data, root->height);
        inorderTraversal(root->right);
    }
}

// Function to perform a preorder traversal
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d (Height: %d) ", root->data, root->height);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform a postorder traversal
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d (Height: %d) ", root->data, root->height);
    }
}

// Main function
int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Height of the Root Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Height of the Root Node: %d\n", getHeight(root));
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
