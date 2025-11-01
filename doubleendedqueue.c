#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

void insert_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
    printf("%d inserted at front.\n", x);
}

void insert_rear(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
    printf("%d inserted at rear.\n", x);
}

void delete_front() {
    if (front == -1) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from front.\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void delete_rear() {
    if (front == -1) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from rear.\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display() {
    int i;
    if (front == -1) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque elements are: ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, type, x;

    printf("\n--- Double Ended Queue (DEQUE) using Array ---\n");
    printf("Select the type of DEQUE:\n");
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter your choice: ");
    scanf("%d", &type);

    while (1) {
        if (type == 1) {
            printf("\n--- Input Restricted Deque Menu ---\n");
            printf("1. Insert at rear\n");
            printf("2. Delete from front\n");
            printf("3. Delete from rear\n");
            printf("4. Display\n");
            printf("5. Exit\n");
        } else if (type == 2) {
            printf("\n--- Output Restricted Deque Menu ---\n");
            printf("1. Insert at front\n");
            printf("2. Insert at rear\n");
            printf("3. Delete from front\n");
            printf("4. Display\n");
            printf("5. Exit\n");
        } else {
            printf("Invalid choice! Exiting...\n");
            exit(0);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (type == 1) {
                    printf("Enter element to insert at rear: ");
                    scanf("%d", &x);
                    insert_rear(x);
                } else {
                    printf("Enter element to insert at front: ");
                    scanf("%d", &x);
                    insert_front(x);
                }
                break;

            case 2:
                if (type == 1)
                    delete_front();
                else {
                    printf("Enter element to insert at rear: ");
                    scanf("%d", &x);
                    insert_rear(x);
                }
                break;

            case 3:
                if (type == 1)
                    delete_rear();
                else
                    delete_front();
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