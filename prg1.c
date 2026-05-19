#include <stdio.h>

int main()
{
    int n, i, j;
    int cost[20][20], parent[20];

    int ne = 1;          // number of edges
    int min_cost = 0;

    printf("Enter the no. of vertices:");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");

    for(i = 1; i <= n; i++)
    {
        parent[i] = 0;

        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nThe edges of spanning tree are\n");

    while(ne < n)
    {
        int min = 999;
        int a, b, u, v;

        // Find minimum edge
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find parent of u
        while(parent[u] != 0)
        {
            u = parent[u];
        }

        // Find parent of v
        while(parent[v] != 0)
        {
            v = parent[v];
        }

        // If no cycle, add edge
        if(u != v)
        {
            printf("Edge %d\t(%d->%d)=%d\n", ne++, a, b, min);

            min_cost += min;
            parent[v] = u;
        }

        // Remove edge from matrix
        cost[a][b] = 999;
        cost[b][a] = 999;
    }

    printf("\nMinimum cost=%d\n", min_cost);

    return 0;
}
