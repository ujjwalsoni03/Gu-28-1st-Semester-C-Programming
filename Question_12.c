#include <stdio.h>
#include <stdlib.h>

void apply_transaction(int *balance, char *operation, double value)
{
    // Apply the operation based on the operator type
    if (operation[0] == '+')
    {
        *balance += (int)value;
    }
    else if (operation[0] == '-')
    {
        *balance -= (int)value;
    }
    else if (operation[0] == '*')
    {
        *balance = (int)(*balance * value);
    }
    else if (operation[0] == '/')
    {
        if (value == 0)
        {
            printf("Error: Division by zero is not allowed\n");
            return;
        }
        *balance /= (int)value;
    }
    else if (operation[0] == '%')
    {
        *balance %= (int)value;
    }
    else if (operation[0] == '&')
    {
        *balance &= (int)value;
    }
    else if (operation[0] == '|')
    {
        *balance |= (int)value;
    }
    else if (operation[0] == '^')
    {
        *balance ^= (int)value;
    }
    else if (operation[0] == '<')
    {
        *balance <<= (int)value;
    }
    else if (operation[0] == '>')
    {
        *balance >>= (int)value;
    }
    else
    {
        printf("Error: Invalid operation %s\n", operation);
    }
}

int main()
{
    int balance;
    char operation[5];
    double value;

    // Read the initial balance
    scanf("%d", &balance);

    while (1)
    {
        // Read the next operation
        scanf("%s", operation);

        if (operation[0] == 'q')
        {
            break; // Quit if 'q' is entered
        }

        // Read the value for the operation
        if (operation[0] == '*' || operation[0] == '/' || operation[0] == '=')
        {
            // Read floating point values for multiplication or division
            scanf("%lf", &value);
        }
        else
        {
            // Read integer values for all other operations
            scanf("%lf", &value); // We use double for consistency in input parsing
        }

        // Apply the transaction
        apply_transaction(&balance, operation, value);
    }

    // Output the final balance
    printf("Final Balance: %d\n", balance);

    return 0;
}