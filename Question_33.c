#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
void reverseWords(char *sentence) { 
    char *words[100]; 
    int wordCount = 0; 
    char *token = strtok(sentence, " "); 
    while (token != NULL) { 
        words[wordCount++] = token; 
        token = strtok(NULL, " "); 
    } 
    for (int i = wordCount - 1; i >= 0; i--) { 
        printf("%s", words[i]); 
        if (i != 0) { 
            printf(" "); 
        } 
    } 
    printf("\n"); 
} 
  
int main() { 
    char *sentence = (char *)malloc(1000 * sizeof(char)); 
    if (sentence == NULL) { 
        printf("Memory allocation failed\n"); 
return 1; 
} 
fgets(sentence, 1000, stdin); 
sentence[strcspn(sentence, "\n")] = '\0'; 
reverseWords(sentence); 
free(sentence); 
return 0; 
}