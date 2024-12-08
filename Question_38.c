#include <stdio.h> 
  
int count_words(char arr[]) { 
    int count = 0, i = 0; 
    int in_word = 0; 
  
    while (arr[i] != '\0') { 
        if (arr[i] != ' ' && !in_word) { 
            in_word = 1; 
            count++; 
        } else if (arr[i] == ' ') { 
            in_word = 0; 
        } 
        i++; 
    } 
  
    return count; 
} 
  
int main() { 
    char arr[101];  
    fgets(arr, 101, stdin); 
  
    int word_count = count_words(arr); 
printf("%d\n", word_count); 
return 0; 
}