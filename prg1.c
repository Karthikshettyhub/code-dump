#include <stdio.h>

#define INF 999

int parent[20];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

void union_set(int u, int v) {
    parent[v] = u;
}

int main() {

    int n, i, j;
    int cost[20][20];
    int ne = 1;
    int min_cost = 0;

    printf("Enter the no. of vertices:");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");

    for(i = 1; i <= n; i++) {
        parent[i] = 0;

        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nThe edges of spanning tree are\n");

    while(ne < n) {

        int min = INF;
        int a = 0, b = 0, u, v;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {

                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v) {

            printf("Edge %d\t(%d->%d)=%d\n", ne++, a, b, min);

            min_cost += min;
            union_set(u, v);
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost=%d\n", min_cost);

    return 0;
}
