#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort using pointers
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function using pointers
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Binary search function using pointers
int binary_search(int *arr, int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to calculate the median using pointers
float calculate_median(int *arr, int n) {
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        return arr[n / 2];
    }
}

int main() {
    int n, x;

    // Input the number of elements
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1; // Memory allocation failed
    }

    // Input the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search
    scanf("%d", &x);

    // Sort the array using quicksort
    quicksort(arr, 0, n - 1);

    // Print the sorted array with appropriate space formatting
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        printf(" ");  // Space after each number including the last one
    }
    printf("\n");

    // Calculate and print the median
    float median = calculate_median(arr, n);
    printf("%.2f\n", median);

    // Perform binary search and print the result
    int search_index = binary_search(arr, n, x);
    printf("%d\n", search_index);

    // Free the allocated memory
    free(arr);

    return 0;
}