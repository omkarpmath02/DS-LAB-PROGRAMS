#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Global heads
struct Node* poly1 = NULL;
struct Node* poly2 = NULL;
struct Node* polySum = NULL;

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// INSERT IN ASCENDING ORDER OF POWER
struct Node* insertTerm(struct Node* head, int coeff, int pow) {

    struct Node* newNode = createNode(coeff, pow);

    // Insert at beginning if list is empty or power is smaller
    if (head == NULL || pow < head->pow) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    // Move forward while next power is <= new power
    while (temp->next != NULL && temp->next->pow <= pow) {
        temp = temp->next;
    }

    // Insert in between / at end
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow < p2->pow) {   // ascending order comparison
            result = insertTerm(result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p1->pow > p2->pow) {
            result = insertTerm(result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
        else {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
                result = insertTerm(result, sumCoeff, p1->pow);

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &pow);
        poly1 = insertTerm(poly1, coeff, pow);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &pow);
        poly2 = insertTerm(poly2, coeff, pow);
    }

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    polySum = addPolynomials(poly1, poly2);

    printf("\nSum = ");
    display(polySum);

    return 0;
}
