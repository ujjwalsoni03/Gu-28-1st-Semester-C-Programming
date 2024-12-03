#include <stdio.h> 
  
int main() { 
    char T; 
    int E; 
  
    scanf("%c", &T); 
    scanf("%d", &E); 
  
    if (T == 'R') { 
        if (E == 1) { 
            printf("ALLOW EMERGENCY\n"); 
        } else { 
            printf("STOP\n"); 
        } 
    } else if (T == 'Y') { 
        if (E == 1) { 
            printf("ALLOW EMERGENCY\n"); 
        } else { 
            printf("PREPARE TO STOP\n"); 
        } 
    } else if (T == 'G') { 
        if (E == 1) { 
            printf("CLEAR THE WAY\n"); 
        } else { 
            printf("PROCEED\n"); 
        } 
    } 
  
    return 0; 
}