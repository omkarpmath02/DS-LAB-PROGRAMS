#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *root = NULL;

node *createnode(int val){
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void bst( int val){
    node *newnode = createnode(val);

    if (root == NULL) {
        root = newnode;
        return;
    }

    node *curr = root;
    node *parent = NULL;

    while(curr != NULL){
        parent = curr;
         
        if(val > curr->data){
            curr = curr->right;
        } else if(val <curr->data){
            curr = curr->left;
        } else {
            return;
        }
    }
     if(val > parent->data){
            parent->right = newnode;
    } else {
            parent->left = newnode;
        }
}

void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void preorder(node *root){
    if(root !=  NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

int main(){
    int ch,val;

    while(1){
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                bst(val);   
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
