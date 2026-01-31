#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push element onto stack */
void push(char ch)
{
    stack[++top] = ch;
}

/* Pop element from stack */
char pop()
{
    return stack[top--];
}

/* Check if parentheses are valid */
int isValid(char expr[])
{
    int i;
    char temp;

    for (i = 0; expr[i] != '\0'; i++)
    {
        /* If opening bracket, push */
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(expr[i]);
        }
        /* If closing bracket */
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (top == -1)
                return 0;   // no matching opening

            temp = pop();

            if ((expr[i] == ')' && temp != '(') ||
                (expr[i] == '}' && temp != '{') ||
                (expr[i] == ']' && temp != '['))
                return 0;
        }
    }

    /* If stack is empty, valid */
    return (top == -1);
}

int main()
{
    char expr[MAX];

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isValid(expr))
        printf("Valid parentheses\n");
    else
        printf("Invalid parentheses\n");

    return 0;
}
