#include <stdio.h>

#define MAX 20

int visited[MAX];

// Depth First Search
void DFS(int adj[MAX][MAX], int n, int start) {
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, n, i);
        }
    }
}

int main() {
    int adj[MAX][MAX];
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start DFS from vertex 0
    DFS(adj, n, 0);

    // Check if all vertices are visited
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT CONNECTED.\n");

    return 0;
}
