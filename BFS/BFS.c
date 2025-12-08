#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v){
    if(rear == MAX-1){
        printf("Overflow");
        return;
    }

    if(front ==-1){
        front=0;
    }

    queue[++rear] = v;
}


int dequeue(){
    if(front ==-1 || front>rear){
        return -1;
    }

    return queue[front++];
}


void BFS(int adj[MAX][MAX], int n, int start){
    int i, current;

    for(i=0; i<n; i++){
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    while((current = dequeue()) != -1){
        printf("%d", current);

    for(int i=0 ;i<n; i++){
        if(adj[current][i]==1 && !visited[i]){
            enqueue(i);
            visited[i] =1;
        }
    }
}
}

int main(){
    int adj[MAX][MAX];
    int n,i,j,start;

    printf("Enter no of vertices");
    scanf("%d", &n);
    printf("Enter adjecency matrix");

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d",&adj[i][j]);
        }
    }

    printf("enter the start vertex");
    scanf("%d", &start);
    BFS(adj,n,start);
    return 0;
}
