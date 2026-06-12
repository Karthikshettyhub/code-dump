#include<stdio.h>

int weight[10], profit[10], n;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// i = current item index, capacity = remaining bag space
int knapsack(int i, int capacity) {
    // Base case: last item
    if (i == n)
        return (weight[i] > capacity) ? 0 : profit[i];

    // If current item doesn't fit, skip it
    if (weight[i] > capacity)
        return knapsack(i + 1, capacity);

    // Choice: skip item OR take item (whichever gives more profit)
    return max(
        knapsack(i + 1, capacity),                          // don't take item i
        knapsack(i + 1, capacity - weight[i]) + profit[i]   // take item i
    );
}

int main() {
    int m, maxProfit;

    printf("\nEnter the no. of objects:");
    scanf("%d", &n);

    printf("\nEnter the knapsack capacity:");
    scanf("%d", &m);

    printf("\nEnter profit followed by weight:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &profit[i], &weight[i]);

    maxProfit = knapsack(1, m);
    printf("\nMax profit=%d", maxProfit);
    return 0;
}
