#include <stdio.h>
#define INF 999

void dij(int n, int v, int cost[10][10], int dist[10])
{
    int i, w, u, count, min;
    int flag[10] = {0};

    // initialize distances from source
    for(i = 0; i < n; i++)
    {
        dist[i] = cost[v][i];
    }

    flag[v] = 1;
    count = 1;

    while(count < n)
    {
        min = INF;
        // pick minimum distance unvisited node
        for(w = 0; w < n; w++)
        {
            if(dist[w] < min && !flag[w])
            {
                min = dist[w];
                u = w;
            }
        }

        flag[u] = 1;
        count++;

        // relax edges
        for(w = 0; w < n; w++)
        {
            if(!flag[w] && dist[u] + cost[u][w] < dist[w])
            {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main()
{
    int n, v, i, j;
    int cost[10][10], dist[10];

    printf("\n Enter the number of nodes:");
    scanf("%d", &n);

    printf("\n Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\n Enter the source matrix:");
    scanf("%d", &v);

    dij(n, v, cost, dist);

    printf("\n Shortest path:\n");
    for(i = 0; i < n; i++)
    {
        if(i != v)
        {
            printf("%d->%d,cost=%d\n", v, i, dist[i]);
        }
    }

    return 0;
}
