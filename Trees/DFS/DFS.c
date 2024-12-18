#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void initGraph(int graph[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void printGraph(int graph[MAX][MAX], int n) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void addElements(int graph[MAX][MAX], int n) {
    int data;
    printf("Enter the adjacency matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element at index %d %d: ", i + 1, j + 1);
            scanf("%d", &data);
            graph[i][j] = data;
        }
    }
}

void dfs(int vertex, int n) {
    visited[vertex] = 1;
    printf("Visited: %d\n", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] != 0 && !visited[i]) {
            dfs(i, n);
        }
    }
}

void bfs(int vertex, int n) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = vertex;
    int curr;
    visited[vertex] = 1;

    while (front < rear) {
        curr = queue[front++];
        printf(" visited : %d", curr);
        for (int i = 0; i < n; i++) {
            if (graph[curr][i] != 0 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    initGraph(graph, n);

    addElements(graph, n);

    printGraph(graph, n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal:\n");
    bfs(startVertex, n);

    return 0;
}
