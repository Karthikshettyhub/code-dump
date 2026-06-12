#include <stdio.h>
#include <math.h>

int n;
int x[10];   // x[row] = column where queen is placed
int count = 0;

// is it safe to place queen at (row, col)?
int isSafe(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (x[i] == col)                        // same column
            return 0;
        if (abs(x[i] - col) == abs(i - row))    // same diagonal
            return 0;
    }
    return 1;
}

void printBoard()
{
    count++;
    printf("\nSolution %d\n", count);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%c\t", x[i] == j ? 'Q' : 'X');
        printf("\n");
    }
}

void solve(int row)
{
    // all rows filled → found a solution
    if (row > n)
    {
        printBoard();
        return;
    }

    // try every column in this row
    for (int col = 1; col <= n; col++)
    {
        if (isSafe(row, col))
        {
            x[row] = col;          // place queen
            solve(row + 1);        // go to next row
            x[row] = 0;            // remove queen (backtrack)
        }
    }
}

int main()
{
    printf("Enter the no.of queens: ");
    scanf("%d", &n);
    solve(1);
    return 0;
}
