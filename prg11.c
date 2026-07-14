#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int temp[MAX_SIZE];

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("********** MERGE SORT PROGRAM **********\n");
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    srand(time(NULL));

    printf("Array elements to be sorted are:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeSort(arr, 0, n - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken =
        (end.tv_sec - start.tv_sec) * 1e9 +
        (end.tv_nsec - start.tv_nsec);

    printf("\nThe sorted elements are:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nThe time taken to sort is %.0f nanoseconds\n", time_taken);

    return 0;
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (int x = low; x <= high; x++)
        arr[x] = temp[x];
}
