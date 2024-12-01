#include <stdio.h> 
#include <limits.h> 
  
int main() { 
    long long n; 
    scanf("%lld", &n); 
  
    int fits_short = 0, fits_long = 0, fits_unsigned_short = 0, fits_unsigned_long = 0; 
  
    if (n >= SHRT_MIN && n <= SHRT_MAX) { 
        printf("Fits in short int\n"); 
        fits_short = 1; 
    } 
    if (n >= LONG_MIN && n <= LONG_MAX) { 
        printf("Fits in long int\n"); 
        fits_long = 1; 
    } 
    if (n >= 0 && n <= USHRT_MAX) { 
        printf("Fits in unsigned short int\n"); 
        fits_unsigned_short = 1; 
    } 
    if (n >= 0 && n <= ULONG_MAX) { 
        printf("Fits in unsigned long int\n"); 
        fits_unsigned_long = 1; 
    } 
  
    if (!(fits_short || fits_long || fits_unsigned_short || fits_unsigned_long)) { 
        printf("Does not fit in any type\n"); 
    } else if (!fits_short || !fits_long || !fits_unsigned_short || !fits_unsigned_long) { 
        printf("Does not fit in any type\n"); 
    } 
  
    return 0; 
} 
  
  
 