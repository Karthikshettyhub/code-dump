#include <stdio.h>
#define MAX 10
int set[MAX];
int chosen[MAX];
int n, target;

void findSubsets(int pos, int currentSum)
{
    // Base case: checked all elements
    if (pos == n)
    {
        if (currentSum == target)
        {
            for (int i = 0; i < n; i++)
                if (chosen[i] == 1)
                    printf("%d ", set[i]);
            printf("\n");
        }
        return;
    }
    // Choice 1: INCLUDE set[pos]
    chosen[pos] = 1;
    findSubsets(pos + 1, currentSum + set[pos]);
    // Choice 2: EXCLUDE set[pos]
    chosen[pos] = 0;
    findSubsets(pos + 1, currentSum);
}

int main()
{
    int totalSum = 0;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    printf("\nEnter the set in increasing order:");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);
    printf("\nEnter the max subset value:");
    scanf("%d", &target);
    for (int i = 0; i < n; i++)
        totalSum += set[i];
    if (totalSum < target || set[0] > target)
        printf("\nNo subset possible");
    else
        findSubsets(0, 0);
    return 0;
}
