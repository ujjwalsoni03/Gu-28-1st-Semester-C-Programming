#include <stdio.h>

// Global variable to track the total number of transactions
int total_transactions = 0;

// Static array to hold account balances, initialized in the main program
static float balances[10];

// Function to perform a transaction on a specific account
void perform_transaction(int n, int account_number, char type, float amount) {
    // Convert account_number to 0-index for internal array access
    int index = account_number - 1;

    // Ensure the account number is valid
    if (account_number < 1 || account_number > n) {
        return;
    }

    if (type == 'D') {
        // Deposit amount
        balances[index] += amount;
        printf("Account %d Balance: %.2f\n", account_number, balances[index]);
    } else if (type == 'W') {
        // Withdrawal amount, check if sufficient funds
        if (amount <= balances[index]) {
            balances[index] -= amount;
        }
        // Print the balance regardless of whether the withdrawal succeeded
        printf("Account %d Balance: %.2f\n", account_number, balances[index]);
    }

    // Increment global transaction counter
    total_transactions++;
}

int main() {
    int n, t;

    // Input number of accounts
    scanf("%d", &n);
    
    // Read initial balances for each account
    for (int i = 0; i < n; i++) {
        scanf("%f", &balances[i]);
    }

    // Input number of transactions
    scanf("%d", &t);

    // Process each transaction
    for (int i = 0; i < t; i++) {
        int account_number;
        char type;
        float amount;

        // Read transaction details
        scanf("%d %c %f", &account_number, &type, &amount);

        // Perform the transaction
        perform_transaction(n, account_number, type, amount);
    }

    // Display total number of transactions performed
    printf("Total Transactions: %d\n", total_transactions);

    return 0;
}