#include <stdio.h>

int main() {
    int N;  // Number of booking requests
    int roomRates[10] = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550};  // Rates for rooms 1 to 10
    
    // Read the number of booking requests
    scanf("%d", &N);
    
    // Process each booking request
    for (int i = 0; i < N; i++) {
        int R, S, E;
        
        // Read the room number, start date, and end date
        scanf("%d %d %d", &R, &S, &E);
        
        // Check if the booking is valid
        if (S > E) {
            // Invalid booking if start date is after the end date
            printf("Invalid booking\n");
        } else {
            // Valid booking, calculate the total cost
            int nights = E - S + 1;  // Number of nights of the stay
            int cost = nights * roomRates[R - 1];  // Calculate the cost based on room number
            
            // Output the total cost
            printf("%d\n", cost);
        }
    }

    return 0;
}
