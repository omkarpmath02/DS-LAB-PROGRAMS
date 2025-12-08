#include<stdio.h>
#define MAX 20
int visited[MAX];

void DFS(int adj[MAX][MAX], int n, int start){
    visited[start] = 1;
    for(int i=0; i<n; i++){
        if(adj[start][i]==1 && !visited[i]){
            DFS(adj,n,i);
        }
    }
}

int main(){
    int adj[MAX][MAX];
    int n;
    printf("Enter vertices");
    scanf("%d", &n);

    printf("Enter adj matrix");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        visited[i] = 0;
    }

    DFS(adj,n,0);

    int connected =1;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            connected = 0;
            break;
        }
    }

    if(connected){
        printf("connected");
    } else {
        printf("not connected");
    }
}
