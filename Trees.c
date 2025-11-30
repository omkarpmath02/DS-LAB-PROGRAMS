#include <stdio.h>
#include <stdlib.h>

// Node structure (singly linked list style, but used for BST)
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Global root pointer
Node *root = NULL;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST (pass by value – does NOT return root)
void insert(Node *r, int value) {
    Node *temp = createNode(value);

    // If the tree is empty, assign root directly
    if (root == NULL) {
        root = temp;
        return;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL) {
        parent = current;

        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else {
            printf("Duplicate value not allowed!\n");
            free(temp);
            return;
        }
    }

    // Attach new node to correct side
    if (value < parent->data)
        parent->left = temp;
    else
        parent->right = temp;
}

// Inorder Traversal (L, Root, R)
void inorder(Node *r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

// Preorder Traversal (Root, L, R)
void preorder(Node *r) {
    if (r != NULL) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

// Postorder Traversal (L, R, Root)
void postorder(Node *r) {
    if (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(root, value);   // root passed by value
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
