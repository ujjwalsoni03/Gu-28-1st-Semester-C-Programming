#include <stdio.h>

int main() {
    int N;
    
    // Input the size of the array
    scanf("%d", &N);
    
    int arr[N];
    
    // Input the array elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize the min and max with the first element
    int min = arr[0], max = arr[0];
    
    // Traverse the array to find the min and max
    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Compute the maximum difference
    int maxDiff = max - min;
    
    // Output the result
    printf("%d\n", maxDiff);
    
    return 0;
}
