#include <stdio.h> 
#define CALC(a, b, c, d) (((a) * (b) + (c)) / (d)) 
int main() { 
int a, b, c, d; 
scanf("%d %d %d %d", &a, &b, &c, &d); 
int intermediate1 = a * b; 
int intermediate2 = intermediate1 + c; 
int finalResult = CALC(a, b, c, d); 
printf("Intermediate result of a * b: %d\n", intermediate1); 
printf("Intermediate result of a * b + c: %d\n", 
intermediate2); 
printf("Final result of (a * b + c) / d: %d\n", finalResult); 
return 0; 
} 
