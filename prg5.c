#include<stdio.h>

int adj[10][10], n, indegree[10];

void findIndegree() {
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += adj[i][j];      // count incoming edges to j
        indegree[j] = sum;
    }
}

void topologicalSort() {
    int result[10], stack[10], top = -1, count = 0;

    findIndegree();

    // Push all jobs with no prerequisites
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            stack[++top] = i;
    }

    while (top != -1) {
        int u = stack[top--];   // pick a job with 0 indegree
        result[count++] = u;

        // Reduce indegree of jobs that depended on u
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0)
                    stack[++top] = v;
            }
        }
    }

    printf("The topological Sequence is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
}

int main() {
    printf("Enter number of jobs:");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    topologicalSort();
    return 0;
}
