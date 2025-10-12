#include<stdio.h>
#define SIZE 5
int top=-1;
int arr[SIZE];


void push(){
if(top == SIZE-1){
    printf("overflow condition\n");
} else{
    int ele;
    printf("enter the element to push = ");
    scanf("%d",&ele);
    top+=1;
    arr[top]=ele;
}
   }

void pop(){
    if(top == -1){
        printf("underflow\n");
    } else {
        top-=1;
    }
}

void display(){
    if(top==-1){
        printf("underflow empty1\n");
    } else{
         printf("\n");
        for(int i=top;i>=0;i--){
           
            printf("%d \t",arr[i]);
        }
    }
}

int main() {
    int arr[10],a;
    while(1){
        printf("\n 1]push \n 2]pop \n 3] display \n 4] exit \n");
        printf("Enter the option = ");
        scanf("%d", &a);
        if(a==4){
            break;
        } else if (a==1){
            push();
        } else if(a==2){
            pop();
        } else if(a==3){
            display();
        } else {
            printf("\n invalid option \n");
        }
    }
}

