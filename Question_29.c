#include <stdio.h>

#define MAX_SIZE 1000000

// Function to get the input array from the user
void getInputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to find the starting index of the subarray with the maximum sum
int findMaxCapacity(int arr[], int n, int k) {
    // Initialize the sum of the first window of size k
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    // Initialize the maximum sum with the sum of the first window
    int maxSum = windowSum;
    int startIndex = 0;

    // Slide the window from the second window to the last possible window
    for (int i = k; i < n; i++) {
        // Slide the window by subtracting the element going out of the window
        // and adding the new element coming into the window
        windowSum += arr[i] - arr[i - k];

        // If the current window sum is greater than the max sum found so far
        // update the max sum and the starting index
        if (windowSum > maxSum) {
            maxSum = windowSum;
            startIndex = i - k + 1;  // The new start index of the window
        }
    }

    return startIndex;
}

int main() {
    int n, k;
    
    // Read n and k
    scanf("%d %d", &n, &k);
    
    int arr[MAX_SIZE];
    
    // Get the input array
    getInputArray(arr, n);
    
    // Find and print the starting index of the subarray with the maximum sum
    printf("%d\n", findMaxCapacity(arr, n, k));
    
    return 0;
}
