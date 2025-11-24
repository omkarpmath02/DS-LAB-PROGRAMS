#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// (a) Create list (Insert at end)
void createList(int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// (b) Insert to the left of a node with target value
void insertLeft(int target, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target value %d not found!\n", target);
        return;
    }

    Node* newNode = createNode(value);

    // Inserting before head
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;
}

// (c) Delete node by specific value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    // Case 1: only one node
    if (temp == head && temp->next == NULL) {
        head = NULL;
    }
    // Case 2: delete head
    else if (temp == head) {
        head = head->next;
        head->prev = NULL;
    }
    // Case 3: delete last node
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // Case 4: delete middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// (d) Display
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    printf("Doubly Linked List: ");
    
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List (Insert at end)\n");
        printf("2. Insert Left of Node\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                createList(value);
                break;

            case 2:
                printf("Insert value: ");
                scanf("%d", &value);
                printf("Left of which value? ");
                scanf("%d", &target);
                insertLeft(target, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}