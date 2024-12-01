#include <stdio.h> 
  
int main() { 
    short a; 
    long long b; 
  
    scanf("%hd", &a); 
    scanf("%lld", &b); 
  
    if (a == 0) { 
        printf("Error\n"); 
        return 1; 
    } 
  
    long long sum = a + b; 
    long long difference = b - a; 
    long long product = (long long)a * b; 
    long long division = b / a; 
  
    printf("Sum: %lld\n", sum); 
    printf("Difference: %lld\n", difference); 
    printf("Product: %lld\n", product); 
    printf("Division: %lld\n", division); 
  
    return 0;
    }
    