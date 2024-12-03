#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int raw_material, labor, overhead;
        scanf("%d %d %d", &raw_material, &labor, &overhead);

        int total_cost = raw_material + labor + overhead;
        float gross_profit = total_cost * 0.20;

        float tax_deduction;
        if (gross_profit > 100000) {
            tax_deduction = gross_profit * 0.15; 
        } else {
            tax_deduction = gross_profit * 0.10; 
        }

        float net_profit = gross_profit - tax_deduction;

        char* status;
        if (net_profit >= 75000) {
            status = "Highly Profitable";
        } else if (net_profit >= 50000) {
            status = "Moderately Profitable";
        } else {
            status = "Less Profitable";
        }

        // Output the results
        printf("Product %d:\n", i);
        printf("Total Production Cost: ₹%d\n", total_cost);
        printf("Gross Profit: ₹%.2f\n", gross_profit);
        printf("Tax Deduction: ₹%.2f\n", tax_deduction);
        printf("Net Profit: ₹%.2f\n", net_profit);
        printf("Product Status: %s\n", status);
    }

    return 0;
}