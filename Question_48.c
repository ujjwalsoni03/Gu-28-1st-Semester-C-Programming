#include <stdio.h>

void modifyArray(int *arr, int n) {
    // Modify the array elements using pointer arithmetic
    for (int i = 0; i < n; i++) {
        *(arr + i) += 4; // Adding 4 to each element
    }
}

int main() {
    int n;

    // Input the size of the array
    //printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n]; // Declare the array of size n

    // Input the array elements
    //printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array before modification
    printf("Array before modification:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Modify the array
    modifyArray(arr, n);

    // Print the array after modification
    printf("Array after modification:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}