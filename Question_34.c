#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
  
int main() { 
    int n; 
    scanf("%d", &n); 
    getchar(); 
     
    char **strings = (char **)malloc(n * sizeof(char *)); 
     
    if (strings == NULL) { 
        printf("Memory allocation failed\n"); 
        return 1; 
    } 
  
    for (int i = 0; i < n; i++) { 
        strings[i] = (char *)malloc(100 * sizeof(char)); 
        if (strings[i] == NULL) { 
            printf("Memory allocation failed\n"); 
            return 1; 
        } 
        fgets(strings[i], 100, stdin); 
        strings[i][strcspn(strings[i], "\n")] = '\0'; 
    } 
  
    int vowels[5] = {0}; 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; strings[i][j] != '\0'; j++) { 
            char c = tolower(strings[i][j]); 
            if (c == 'a') vowels[0]++; 
            else if (c == 'e') vowels[1]++; 
            else if (c == 'i') vowels[2]++; 
            else if (c == 'o') vowels[3]++; 
            else if (c == 'u') vowels[4]++; 
        } 
    } 
  
    printf("a: %d, e: %d, i: %d, o: %d, u: %d\n", vowels[0], vowels[1], vowels[2], vowels[3], 
vowels[4]); 
  
    for (int i = 0; i < n; i++) { 
        free(strings[i]); 
    } 
    free(strings); 
  
    return 0; 
} 
 