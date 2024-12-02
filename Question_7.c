#include <stdio.h>
#include <string.h>

// Define constants
#define MAX_ATM_LOCATION_LENGTH 50

// Define the structure for different transaction types
typedef struct {
    float amount;
    int accountNumber;
} Deposit;

typedef struct {
    float amount;
    int accountNumber;
    char atmLocation[MAX_ATM_LOCATION_LENGTH];
} Withdrawal;

typedef struct {
    float amount;
    int fromAccountNumber;
    int toAccountNumber;
} Transfer;

// Define a union for transaction data
typedef union {
    Deposit deposit;
    Withdrawal withdrawal;
    Transfer transfer;
} TransactionData;

// Define a structure to hold the transaction type and data
typedef struct {
    char transactionType;
    TransactionData data;
} Transaction;

void printTransaction(Transaction *transaction) {
    switch (transaction->transactionType) {
        case 'D':
            printf("Transaction Type: Deposit\n");
            printf("Amount: %.2f\n", transaction->data.deposit.amount);
            printf("Account Number: %d\n", transaction->data.deposit.accountNumber);
            break;
        case 'W':
            printf("Transaction Type: Withdrawal\n");
            printf("Amount: %.2f\n", transaction->data.withdrawal.amount);
            printf("Account Number: %d\n", transaction->data.withdrawal.accountNumber);
            printf("ATM Location: %s\n", transaction->data.withdrawal.atmLocation);
            break;
        case 'T':
            printf("Transaction Type: Transfer\n");
            printf("Amount: %.2f\n", transaction->data.transfer.amount);
            printf("From Account Number: %d\n", transaction->data.transfer.fromAccountNumber);
            printf("To Account Number: %d\n", transaction->data.transfer.toAccountNumber);
            break;
        default:
            break;
    }
}

int main() {
    // Create a transaction instance
    Transaction transaction;

    // Read the transaction type
    scanf(" %c", &transaction.transactionType);

    // Process the input based on the transaction type
    switch (transaction.transactionType) {
        case 'D':
            // Input for Deposit
            scanf("%f %d", &transaction.data.deposit.amount, &transaction.data.deposit.accountNumber);
            break;
        case 'W':
            // Input for Withdrawal
            scanf("%f %d", &transaction.data.withdrawal.amount, &transaction.data.withdrawal.accountNumber);
            getchar();  // To consume the newline character
            fgets(transaction.data.withdrawal.atmLocation, MAX_ATM_LOCATION_LENGTH, stdin);
            // Remove the newline character from ATM location input if present
            transaction.data.withdrawal.atmLocation[strcspn(transaction.data.withdrawal.atmLocation, "\n")] = '\0';
            break;
        case 'T':
            // Input for Transfer
            scanf("%f %d %d", &transaction.data.transfer.amount, &transaction.data.transfer.fromAccountNumber, &transaction.data.transfer.toAccountNumber);
            break;
        default:
            // If the transaction type is invalid, do nothing
            return 1;
    }

    // Print the transaction details
    printTransaction(&transaction);

    return 0;
}