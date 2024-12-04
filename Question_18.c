#include <stdio.h>

int main() {
    int N;  // Number of requests
    int reservedBy = 0;  // 0 means the room is free, otherwise it holds the employee ID
    
    // Read the number of requests
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char command[10];  // To store "RESERVE" or "FREE"
        int employeeID;
        
        // Read each command
        scanf("%s %d", command, &employeeID);
        
        if (strcmp(command, "RESERVE") == 0) {
            // RESERVE request
            if (reservedBy == 0) {
                // Room is free, reserve it
                reservedBy = employeeID;
                printf("Room Reserved\n");
            } else {
                // Room is already reserved by someone else
                printf("Room Already Reserved by Employee %d\n", reservedBy);
            }
        } else if (strcmp(command, "FREE") == 0) {
            // FREE request
            if (reservedBy == 0) {
                // Room is not reserved
                printf("No Reservation to Free\n");
            } else if (reservedBy == employeeID) {
                // Employee is freeing the room they reserved
                reservedBy = 0;  // Free the room
                printf("Room Freed\n");
            } else {
                // The employee trying to free the room is not the one who reserved it
                printf("No Reservation to Free\n");
            }
        }
    }

    return 0;
}
