#include <stdio.h>

// Define the union AccountDetails
typedef union {
    struct {
        float balance;
        float interestRate;
    } savings;
    struct {
        float balance;
        float overdraftLimit;
    } checking;
} AccountDetails;

// Define the structure BankAccount
typedef struct {
    char accountHolderName[100];
    int accountType;
    AccountDetails details;
} BankAccount;

int main() {
    BankAccount account;

    // Read account holder name
    //printf("Enter the account holder's name: ");
    fgets(account.accountHolderName, 100, stdin);
    account.accountHolderName[strcspn(account.accountHolderName, "\n")] = '\0'; // Remove newline

    // Read account type
    //printf("Enter the account type (1 for Savings, 2 for Checking): ");
    scanf("%d", &account.accountType);
    getchar(); // Consume newline character after the integer input

    // Read account details based on account type
    if (account.accountType == 1) {
        //printf("Enter the balance and interest rate: ");
        scanf("%f %f", &account.details.savings.balance, &account.details.savings.interestRate);
        getchar(); // Consume newline character after the float inputs

        // Display Savings Account details
        printf("Savings Account Balance: %.2f\n", account.details.savings.balance);
        printf("Annual Interest Rate: %.2f%%\n", account.details.savings.interestRate);
    } else if (account.accountType == 2) {
        //printf("Enter the balance and overdraft limit: ");
        scanf("%f %f", &account.details.checking.balance, &account.details.checking.overdraftLimit);
        getchar(); // Consume newline character after the float inputs

        // Display Checking Account details
        printf("Checking Account Balance: %.2f\n", account.details.checking.balance);
        printf("Overdraft Limit: %.2f\n", account.details.checking.overdraftLimit);
    } else {
        //printf("Invalid account type.\n");
    }

    return 0;
}