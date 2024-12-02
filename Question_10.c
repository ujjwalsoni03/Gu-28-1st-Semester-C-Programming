#include <stdio.h>

// Function to grant permission for a device (set a bit)
void grant_permission(int *user_control, int device_bit) {
    *user_control |= (1 << device_bit);  // Set the bit at device_bit to 1 (grant permission)
}

// Function to revoke permission for a device (clear a bit)
void revoke_permission(int *user_control, int device_bit) {
    *user_control &= ~(1 << device_bit); // Set the bit at device_bit to 0 (revoke permission)
}

// Function to check if a user has control over a device (check if the bit is set)
int has_permission(int user_control, int device_bit) {
    return (user_control & (1 << device_bit)) != 0;  // Check if the bit at device_bit is set to 1
}

// Function to combine permissions from two users
int combine_permissions(int user_a_control, int user_b_control) {
    return user_a_control | user_b_control;  // Combine permissions using bitwise OR
}

// Function to display the binary representation of the control register
void display_binary(int user_control) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (user_control >> i) & 1);  // Print the bits from most significant to least
    }
    printf("\n");
}

int main() {
    // User A and User B Control Registers
    int user_a_control, user_b_control;
    
    // Get input for User A and User B control registers
    
    scanf("%d", &user_a_control);  // Read User A's control register
    
    
    scanf("%d", &user_b_control);  // Read User B's control register

    // Operation 1: Grant Lights (bit 0) to User A
    grant_permission(&user_a_control, 0);  // Granting permission for Lights (bit 0)
    printf("User A Control Register after Granting Lights: %d\n", user_a_control);

    // Operation 2: Revoke Music System (bit 7) from User B
    revoke_permission(&user_b_control, 7);  // Revoking permission for Music System (bit 7)
    printf("User B Control Register after Revoking Music System: %d\n", user_b_control);

    // Operation 3: Check if User A has control over Cameras (bit 3)
    int cameras_permission = has_permission(user_a_control, 3);
    printf("User A has control over Cameras: %s\n", cameras_permission ? "Yes" : "No");

    // Operation 4: Combine User A and User B's control registers to create User C
    int user_c_control = combine_permissions(user_a_control, user_b_control);
    printf("Combined Control Register (User C): %d\n", user_c_control);

    // Display User A's control register in binary format
    printf("User A Control Register in Binary: ");
    display_binary(user_a_control);

    return 0;
}