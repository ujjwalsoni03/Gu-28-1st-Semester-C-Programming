#include <stdio.h> 
  
int main() { 
    int n; 
    scanf("%d", &n); 
  
    for (int i = 0; i < n; i++) { 
        int a; 
        float b; 
        char op; 
        double c, result = 0.0; 
  
        // Input each set 
        scanf("%d %f %c %lf", &a, &b, &op, &c); 
  
        // Perform operations based on the operator 
        if (op == '+') { 
            result = a + b + c; 
        } else if (op == '-') { 
            result = a - b + c; 
        } else if (op == '*') { 
            result = a * b + c; 
        } else if (op == '/') { 
            if (b != 0.0) { 
                result = a / b + c; 
            } else { 
                result = c; // Division by zero, only add `c` 
            } 
        } 
  
        // Print the result with two decimal places 
        printf("%.2lf\n", result); 
    } 
  
    return 0; 
} 
