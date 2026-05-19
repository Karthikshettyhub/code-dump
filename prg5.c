#include <stdio.h>

int a[10][10], n, indeg[10];

void find_indegre()
{
    int i, j, sum;

    for(j = 0; j < n; j++)
    {
        sum = 0;

        for(i = 0; i < n; i++)
            sum += a[i][j];

        indeg[j] = sum;
    }
}

void topology()
{
    int i, u, v;
    int s[10], t[10];
    int top = -1, k = 0;

    find_indegre();

    // push all nodes with indegree 0
    for(i = 0; i < n; i++)
    {
        if(indeg[i] == 0)
            s[++top] = i;
    }

    while(top != -1)
    {
        u = s[top--];
        t[k++] = u;

        for(v = 0; v < n; v++)
        {
            if(a[u][v] == 1)
            {
                indeg[v]--;

                if(indeg[v] == 0)
                    s[++top] = v;
            }
        }
    }

    printf("The topological Sequence is:\n");

    for(i = 0; i < n; i++)
        printf("%d ", t[i]);
}

int main()
{
    int i, j;

    printf("Enter number of jobs:");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    topology();

    return 0;
}
