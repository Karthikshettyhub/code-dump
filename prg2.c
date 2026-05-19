#include <stdio.h>

int main()
{
    int n, i, j;
    int cost[10][10];
    int visited[10] = {0};

    int ne = 1;
    int mincost = 0;

    int a, b, u, v, min;

    printf("\n Enter the number of nodes:");
    scanf("%d", &n);

    printf("\n Enter the adjacency matrix:\n");

    // Input matrix
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    // Start from node 1
    visited[1] = 1;

    printf("\n");

    while(ne < n)
    {
        min = 999;

        // Find minimum edge from visited node
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min && visited[i] != 0)
                {
                    min = cost[i][j];

                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Add edge if new node found
        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);

            mincost += min;

            visited[b] = 1;
        }

        // Remove used edge
        cost[a][b] = 999;
        cost[b][a] = 999;
    }

    printf("\n Minimun cost=%d", mincost);

    return 0;
}
