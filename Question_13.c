#include <stdio.h>

int main() {
    int savings_balance;
    float current_balance;
    double fixed_deposit_balance;
    scanf("%d", &savings_balance);
    scanf("%f", &current_balance);
    scanf("%lf", &fixed_deposit_balance);
    double total_balance = (double)savings_balance + (double)current_balance + fixed_deposit_balance;
    printf("Total Balance: %.2lf\n", total_balance);
    return 0;
}