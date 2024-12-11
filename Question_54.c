#include <stdio.h> 
struct ComplexNumber { 
float real; 
float imaginary; 
}; 
struct ComplexNumber add(struct ComplexNumber c1, 
struct ComplexNumber c2) { 
struct ComplexNumber result; 
result.real = c1.real + c2.real; 
result.imaginary = c1.imaginary + c2.imaginary; 
return result; 
} 
struct ComplexNumber subtract(struct ComplexNumber c1, 
struct ComplexNumber c2) { 
struct ComplexNumber result; 
result.real = c1.real - c2.real; 
result.imaginary = c1.imaginary - c2.imaginary; 
return result; 
} 
struct ComplexNumber multiply(struct ComplexNumber c1, 
struct ComplexNumber c2) { 
struct ComplexNumber result; 
result.real = c1.real * c2.real - c1.imaginary * c2.imaginary; 
result.imaginary = c1.real * c2.imaginary + c1.imaginary * 
c2.real; 
return result; 
} 
struct ComplexNumber divide(struct ComplexNumber c1, 
struct ComplexNumber c2) { 
struct ComplexNumber result; 
float denominator = c2.real * c2.real + c2.imaginary * 
c2.imaginary; 
if (denominator == 0) { 
printf("Division by zero is not possible.\n"); 
result.real = 0; 
result.imaginary = 0; 
return result; 
} 
result.real = (c1.real * c2.real + c1.imaginary * 
c2.imaginary) / denominator; 
result.imaginary = (c1.imaginary * c2.real - c1.real * 
c2.imaginary) / denominator; 
return result; 
} 
void printComplex(struct ComplexNumber c) { 
if (c.imaginary >= 0) { 
printf("%.2f + %.2fi\n", c.real, c.imaginary); 
} else { 
printf("%.2f - %.2fi\n", c.real, -c.imaginary); 
} 
} 
int main() { 
struct ComplexNumber c1, c2, result; 
scanf("%f %f", &c1.real, &c1.imaginary); 
scanf("%f %f", &c2.real, &c2.imaginary); 
result = add(c1, c2); 
printf("Addition: "); 
printComplex(result); 
result = subtract(c1, c2); 
printf("Subtraction: "); 
printComplex(result); 
result = multiply(c1, c2); 
printf("Multiplication: "); 
printComplex(result); 
result = divide(c1, c2); 
printf("Division: "); 
printComplex(result); 
return 0; 
}