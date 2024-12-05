#include <stdio.h>
float calculateTotalCost(int items[], int n) {
    if (n == 0) {
        return 0.0;
    }
    return items[n - 1] + calculateTotalCost(items, n - 1);
}
// Function to apply discount based on the number of items
float applyDiscount(float totalCost, int itemCount) {
    float discount = 0.0;
    if (itemCount >= 1 && itemCount <= 5) {
        discount = 0.05 * totalCost;
    } else if (itemCount >= 6 && itemCount <= 10) {
        discount = 0.10 * totalCost;
    } else if (itemCount > 10) {
        discount = 0.15 * totalCost;
    }
    return totalCost - discount;
}
int main() {
    int N;
    scanf("%d", &N); // Read number of items
    
    int items[N]; // Array to store the prices of items
    for (int i = 0; i < N; i++) {
        scanf("%d", &items[i]); // Read each item's price
    }
    
    // Calculate the total cost of all items recursively
    float totalCost = calculateTotalCost(items, N);
    
    // Apply discount based on the number of items
    float finalCost = applyDiscount(totalCost, N);
    
    // Output the final cost rounded to two decimal places
    printf("%.2f\n", finalCost);
    
    return 0;
}
