#include <stdio.h> 
#define DEBUG 
int main() { 
int number; 
scanf("%d", &number); 
#ifdef DEBUG 
printf("Debug: Input value is %d\n", number); 
#endif 
if (number % 2 == 0) { 
printf("The number is even\n"); 
} else { 
printf("The number is odd\n"); 
} 
return 0; 
} 
 