#include<stdio.h>
#include<string.h>
#define MAX 10

char stack[MAX];
int top=-1;

void push(char c){
    if(top==MAX -1 ){
        printf("stack overflow");
    } else {
        stack[++top]=c;
    }
}

char pop(){
    if(top==-1){
        return -1;
    } else {
        return stack[top--];
    }
}

char peek(){
    if(top==-1){
        return -1;
    } else{
        return stack[top];
    }
}

int precedence(char c){
    switch(c){
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
    }

    void infixtopostfix(char infix[]){
        char postfix[MAX];
        int k=0;

        for(int i=0; infix[i]!='\0' ;i++){
            char c =infix[i];

            switch(c){
                case '(': 
                    push(c);
                    break;
                case ')': 
                    while (peek()!='(' && top!=-1){
                        postfix[k++]=pop();
                    }
                    pop();
                    break;

                case '+':
                case '-':
                case '/':
                case '*':
                case '^':
                    while(top!=-1 && precedence(peek()) >= precedence(c)){
                        postfix[k++]=pop();
                    }
                    push(c);
                    break;

                default:
                    postfix[k++]=c;        
            }
        }

        while(top!=-1){
            postfix[k++]=pop();
        }
        postfix[k]='\0';
        printf("postfix : %s", postfix);
    }

int main (){
    char infix[MAX];
    printf("Enter Infix exp = ");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}