#include<stdio.h>
#define n 5
int front=-1, rear=-1;
int arr[n];

void insert_front(){
    int num;
    if(front==0 && rear==n-1){
        printf("overflow");
    } else if( front==-1 && rear==-1){
        printf("enter the number =");
        scanf("%d",&num);
        front=0;
        rear=0;
        arr[front] = num;
    // } else if(front==0 && rear!=n-1){
    //     front=n-1;
    //     arr[front]=num;
    } else {
        printf("enter the number =");
        scanf("%d",&num);
        front--;
        arr[front]=num;
    }
    printf("inserted \n");
}

void insert_rear(){
    int num;
    if(rear==(n-1) || front > rear ){
        printf("overflow");
    } else if(front==-1 && rear==-1){
        printf("enter the number =");
        scanf("%d",&num);
        front=0;
        rear=0;
        arr[rear] = num;
    // } else if(rear==n-1 && front!=0){
    //     rear=0;
    //     arr[rear]=num;
    } else {
        printf("enter the number =");
        scanf("%d",&num);
        rear++;
        arr[rear]=num;
    }
    printf("inserted \n");
}

void delete_front(){
    if(front==-1 && rear==-1){
        printf("underflow");    
    } else if(front==0) {
        front=-1;
    } else {
        front++;
    }
}

void delete_rear(){
    if(rear==-1 && front==-1){
        printf("underflow");    
    } else if(rear==0) {
        rear=-1;
    } else {
        rear--;
    }
}

void display(){
    for(int i=front; i<=rear; i=(i+1)%n){
        printf("%d",arr[i]);
        printf("\t");
    }
    printf("\n");
}


void main(){
    // insert_front();
    // insert_front();
    // delete_front();
    // display();
    int var;
     while(1){
    printf("enter the option \n 1]insert front \n 2]insert rear \n 3] delete front \n 4] delete rear \n 5] display \n");
    scanf("%d",&var);
    switch(var){
        case 1: insert_front();
                break;

        case 2: insert_rear();
                break;

        case 3: delete_front();
                break;

        case 4: delete_rear();
                break;

        case 5: display();
                break;
    }
}
}