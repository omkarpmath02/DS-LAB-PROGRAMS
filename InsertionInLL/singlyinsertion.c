#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node* createnode(int data){
    node* newnode = (node*) malloc(sizeof(node));

    if(newnode==NULL){
        printf("Error in memory allocation");
    }

    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}


node* insertatfirst(node *head, int data){
    node *newnode = createnode(data);
    newnode->next = head;
    return newnode;
}


node* insertatend(node *head, int data){
    node *newnode = createnode(data);

    if(head==NULL){
        return newnode;
    }

    node *temp = head;

    while(temp->next != NULL){
        temp=temp->next;
    }

    temp->next = newnode;
    return head;
}


node* insertatpos(node *head, int data, int pos){
    if(pos < 1){
        printf("invalid position");
        return head;
    }

    if(pos==1){
        return insertatfirst(head,data);
    }

    node* newnode = createnode(data);
    node *temp = head;

    for(int i=1; i<pos-1; i++){
        if(temp==NULL){
            printf("invaild position");
            free(newnode);
            return head;
        }
        temp=temp->next;
    }

        if(temp==NULL){
            printf("invaild position");
            free(newnode);
            return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;

}


void display(node *head) {
    if(head==NULL){
        printf("empty");
        return;
    }
    node *temp = head;
    
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void freelist(node *head){
    node *temp;
    while(head != NULL){
        temp = head;
        head=head->next;
        free(temp);
    }
}



int main(){
    node *head = NULL;

    int choice, data, pos;

    
    while(1){
        printf("\n 1.INSERT AT FIRST \n 2.INSERT AT END \n 3.INSERT AT ANY POS \n 4.DISPLAY \n 5. EXIT");

        printf("\n enter choice = ");
        scanf("%d", &choice);


        switch ((choice))
        {
            case 1: printf("Enter data= ");
                    scanf("%d", &data);
                    head = insertatfirst(head,data);
                    display(head);
                    break;
            
            case 2: printf("Enter data= ");
                    scanf("%d", &data);
                    head = insertatend(head,data);
                    display(head);
                    break;

            case 3: printf("Enter data and pos= ");
                    scanf("%d%d", &data, &pos);
                    head = insertatpos(head,data,pos);
                    display(head);
                    break;

            case 4:
                display(head);
                break;

            case 5:
                freelist(head);
                break;

            case 6:
                exit(0);
        }

    }
}

