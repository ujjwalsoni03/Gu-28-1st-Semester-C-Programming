#include <stdio.h>

#define BASE_BONUS_RATE 50.0    // Base bonus rate per performance score point
#define ADDITIONAL_BONUS_RATE 10.0  // Additional bonus rate per work hour

// Function to calculate the base bonus based on performance score
float calculateBaseBonus(float performanceScore) {
    return performanceScore * BASE_BONUS_RATE;
}

// Function to calculate the additional bonus based on work hours
float calculateAdditionalBonus(float workHours) {
    return workHours * ADDITIONAL_BONUS_RATE;
}

// Function to apply adjustment based on employee type
float applyAdjustment(float bonus, char employeeType) {
    if (employeeType == 'P') {
        // 5% reduction for part-time employees
        return bonus * 0.95;
    }
    // No adjustment for full-time employees
    return bonus;
}

int main() {
    int N;
    scanf("%d", &N);  // Read the number of employees

    // Process each employee
    for (int i = 0; i < N; i++) {
        float performanceScore, workHours;
        char employeeType;
        
        // Read the input for each employee
        scanf("%f %f %c", &performanceScore, &workHours, &employeeType);
        
        // Calculate the base and additional bonuses
        float baseBonus = calculateBaseBonus(performanceScore);
        float additionalBonus = calculateAdditionalBonus(workHours);
        
        // Calculate the total bonus before adjustment
        float totalBonus = baseBonus + additionalBonus;
        
        // Apply the adjustment based on employee type
        float finalBonus = applyAdjustment(totalBonus, employeeType);
        
        // Output the final bonus rounded to two decimal places
        printf("%.2f\n", finalBonus);
    }

    return 0;
}
