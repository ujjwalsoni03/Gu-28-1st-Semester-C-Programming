#include <stdio.h>
#include <string.h>

// Function to determine the weight category
const char* getWeightCategory(float weight) {
    if (weight <= 5) {
        return "Lightweight";
    } else if (weight <= 20) {
        return "Standard";
    } else if (weight <= 50) {
        return "Heavy";
    } else {
        return "Overweight";
    }
}

// Function to calculate the shipment cost
float calculateCost(float weight, int distance, const char* type) {
    float rate = 0.0;

    // Domestic shipment rates
    if (strcmp(type, "domestic") == 0) {
        if (weight <= 5) {
            rate = 1.00;
        } else if (weight <= 20) {
            rate = 1.50;
        } else if (weight <= 50) {
            rate = 2.00;
        } else {
            rate = 3.00;
        }
    }
    // International shipment rates
    else if (strcmp(type, "international") == 0) {
        if (weight <= 5) {
            rate = 2.00;
        } else if (weight <= 20) {
            rate = 3.00;
        } else if (weight <= 50) {
            rate = 4.00;
        } else {
            rate = 6.00;
        }
    }

    // Calculate and return the cost
    return rate * distance;
}

int main() {
    int N;
    scanf("%d", &N);  // Read the number of packages

    for (int i = 0; i < N; i++) {
        float weight;
        int distance;
        char type[20];

        // Read the weight, distance, and shipment type
        scanf("%f %d %s", &weight, &distance, type);

        // Determine the weight category
        const char* weightCategory = getWeightCategory(weight);

        // Calculate the cost
        float cost = calculateCost(weight, distance, type);

        // Output the result
        printf("%s\n", weightCategory);
        printf("%s\n", type);
        printf("%.2f\n", cost);
    }

    return 0;
}
