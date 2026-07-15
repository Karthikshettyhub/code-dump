#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int size;
    printf("********* Selection SORT PROGRAM *********\n");
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &size);

    int arr[size];
    srand(time(NULL));

    printf("Array elements to be sorted are: \n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    selectionSort(arr, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);

    printf("Now the Array after Sorting is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nThe time taken to sort is %.10f seconds\n", time_taken);
    printf("******** ******************* *******\n");

    return 0;
}
