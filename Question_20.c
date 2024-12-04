#include <stdio.h>
float calculateTotalCost(float prices[], int quantities[], int n) {
    float totalCost = 0.0;
    for (int i = 0; i < n; i++) {
        totalCost += prices[i] * quantities[i];
        }
    return totalCost;
}

// Function to apply a discount based on the total cost
float applyDiscount(float totalCost) {
    if (totalCost < 50) {
        return totalCost;  // No discount
    } else if (totalCost >= 50 && totalCost <= 100) {
        return totalCost * 0.90;  // 10% discount
    } else {
        return totalCost * 0.80;  // 20% discount
    }
}

// Function to compute the final price after discount
float finalPriceAfterDiscount(float totalCost) {
    return applyDiscount(totalCost);
}

int main() {
    int N;
    scanf("%d", &N);  // Read number of orders
    
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);  // Read the number of items in the current order
        
        float prices[M];     // Array to store the prices of items
        int quantities[M];   // Array to store the quantities of items
        
        // Read the prices and quantities for each item in the order
        for (int j = 0; j < M; j++) {
            scanf("%f %d", &prices[j], &quantities[j]);
        }
        
        // Calculate the total cost of the order
        float totalCost = calculateTotalCost(prices, quantities, M);
        
        // Calculate the final price after applying the discount
        float finalPrice = finalPriceAfterDiscount(totalCost);
        
        // Output the final price rounded to two decimal places
        printf("%.2f\n", finalPrice);
    }
    
    return 0;
}
