#include <stdio.h>
#define MAX 50

int main() {
    int n, m;
    int weight[MAX], profit[MAX];
    double fraction[MAX], ratio[MAX];

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the objects' weights: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter the objects' profits: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter the maximum capacity: ");
    scanf("%d", &m);

    // Step 1: Calculate profit/weight ratio
    for (int i = 0; i < n; i++)
        ratio[i] = (double)profit[i] / weight[i];

    // Step 2: Sort items by ratio in decreasing order (bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // swap ratio
                double tempR = ratio[i]; ratio[i] = ratio[j]; ratio[j] = tempR;
                // swap weight
                int tempW = weight[i]; weight[i] = weight[j]; weight[j] = tempW;
                // swap profit
                int tempP = profit[i]; profit[i] = profit[j]; profit[j] = tempP;
            }
        }
    }

    // Step 3: Greedily fill the knapsack
    int currentWeight = 0;
    double maxProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= m) {
            // Take the whole item
            fraction[i] = 1;
            currentWeight += weight[i];
            maxProfit += profit[i];
        } else {
            // Take only the fraction that fits
            fraction[i] = (m - currentWeight) / (double)weight[i];
            maxProfit += fraction[i] * profit[i];
            break;
        }
    }

    printf("Optimal solution for greedy method: %.1f\n", maxProfit);
    printf("Solution vector for greedy method: ");
    for (int i = 0; i < n; i++)
        printf("%.1f\t", fraction[i]);

    return 0;
}
