#include <stdio.h> 
#include <ctype.h> 
  
void replace_vowels(char arr[], char replacement) { 
    for (int i = 0; arr[i] != '\0'; i++) { 
        char c = arr[i]; 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') { 
            arr[i] = replacement; 
        } 
    } 
} 
  
int main() { 
    char arr[101]; 
    char replacement; 
  
    fgets(arr, sizeof(arr), stdin); 
    scanf("%c", &replacement); 
  
    replace_vowels(arr, replacement); 
  
    printf("%s\n", arr); 
  
    return 0; 
}