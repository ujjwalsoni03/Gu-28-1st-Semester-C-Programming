#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
void removeEveryThirdChar(char *str) { 
    int len = strlen(str); 
    int count = 0; 
     
    for (int i = 2; i < len; i++) { 
        str[i - count] = str[i]; 
        if ((i + 1) % 3 == 0) { 
            count++; 
        } 
    } 
    str[len - count] = '\0'; 
} 
  
int main() { 
    char str[101]; 
    fgets(str, 101, stdin); 
    str[strcspn(str, "\n")] = '\0'; 
  
    removeEveryThirdChar(str); 
  
    printf("%s\n", str); 
return 0; 
}