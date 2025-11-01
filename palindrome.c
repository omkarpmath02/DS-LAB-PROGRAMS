#include <stdio.h>
#include <string.h>
#include <ctype.h>   // for tolower()

#define MAX 100

char deque[MAX];
int front = -1, rear = -1;

// Function to insert character at rear
void insertRear(char ch) {
    if ((rear + 1) % MAX == front) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    deque[rear] = ch;
}

// Function to delete character from front
char deleteFront() {
    char ch;
    if (front == -1) {
        printf("Deque is Empty!\n");
        return '\0';
    }
    ch = deque[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
    return ch;
}

// Function to delete character from rear
char deleteRear() {
    char ch;
    if (front == -1) {
        printf("Deque is Empty!\n");
        return '\0';
    }
    ch = deque[rear];
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
    return ch;
}

// Function to check if the string is palindrome
int isPalindrome(char str[]) {
    front = rear = -1;  // reset deque

    // Insert all characters into deque
    for (int i = 0; i < strlen(str); i++) {
        if (isalnum(str[i])) { // consider only letters and digits
            insertRear(tolower(str[i]));
        }
    }

    // Compare characters from both ends
    while (front < rear) {
        char frontChar = deleteFront();
        char rearChar = deleteRear();
        if (frontChar != rearChar)
            return 0;  // Not palindrome
    }
    return 1; // Palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}