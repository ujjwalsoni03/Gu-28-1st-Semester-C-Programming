#include <stdio.h>
#include <stdlib.h>

// Function to perform the array transformation
int transformArray(int arr[], int n, int x, int y) {
    // Step 1: Element Replacement
    for (int i = 0; i < n; i++) {
        if (arr[i] % x == 0) {
            arr[i] = y;  // Replace with y if divisible by x
        }
    }

    // Step 2: Incremental Sum Update
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i] + arr[i + 1];  // Update each element except the last one
    }

    // Step 3: Output Maximum Value
    int maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];  // Track the maximum value
        }
    }

    return maxValue;  // Return the maximum value found
}

int main() {
    int n;
    
    // Read the size of the array
    scanf("%d", &n);
    
    int arr[n];
    
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x, y;
    
    // Read the values of x and y
    scanf("%d %d", &x, &y);
    
    // Call the transformArray function and print the result
    int result = transformArray(arr, n, x, y);
    printf("%d\n", result);
    
    return 0;
}
