#include <stdio.h>

#define MAX 100

struct Employee {
    int key;
    char name[20];
};

struct Employee HT[MAX];

void initialize(int m) {
    for (int i = 0; i < m; i++) {
        HT[i].key = -1;
    }
}

int hashFunction(int key, int m) {
    return key % m;
}

void insert(int m) {
    struct Employee emp;
    int index;

    printf("\nEnter Employee Key: ");
    scanf("%d", &emp.key);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    index = hashFunction(emp.key, m);

    while (HT[index].key != -1) {
        index = (index + 1) % m;
}

    HT[index] = emp;
    printf("Inserted at address %d\n", index);
}

void display(int m) {
    printf("\nAddress\tKey\tName\n");
    for (int i = 0; i < m; i++) {
        if (HT[i].key != -1)
            printf("%d\t%d\t%s\n", i, HT[i].key, HT[i].name);
        else
            printf("%d\t--\t--\n", i);
    }
}

int main() {
    int m, choice;

    printf("Enter number of memory locations: ");
    scanf("%d", &m);

    initialize(m);

    do {
        printf("\n1.Insert\n2.Display\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(m);
                break;
            case 2:
                display(m);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
